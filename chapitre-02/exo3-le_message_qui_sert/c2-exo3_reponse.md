# REPONSES DE L'EXERCICE 3

## Analyse du premier commit
- Premier commit:
```
commit b50d5072bdeb7a96e3bc583a2f651877fe87adc1 (HEAD -> main)
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Mon Jul 27 21:24:24 2026 +0100

    feat(editmode): overlay respecte la profondeur (X-ray), flushing de selection et aretes a couleur interpolee
    
    OVERLAY AVEC DEPTH (bug 'wireframe selon l'angle') :
    - Les marqueurs de sommets / centres de face etaient dessines en no-depth INCONDITIONNEL
      (DrawDebugTriangle overlay=true en dur) -> ils suivent desormais st->editXray, comme le
      remplissage de face. X-ray OFF = overlay occlus par la geometrie ; X-ray ON = no-depth.
      Le GIZMO reste no-depth dans tous les cas (chemin separe, volontaire).
    - Le lift radial de la cage passe de rad*0.006f a rad*0.0035f : assez pour eviter le
      z-fighting (teste : 0.0015f fait revenir les pointilles), assez peu pour ne plus deborder
      devant une geometrie voisine (cas de la colonne fine signale par l'auteur).
      NOTE : reglage visuel empirique ; le correctif de fond serait un depth-bias cote pipeline
      de lignes plutot qu'un decalage geometrique.
    
    FLUSHING DE SELECTION (facon Blender) : les SOMMETS sont la source de verite ; une arete est
    selectionnee si ses 2 extremites le sont, une face si tous ses sommets le sont. Recalcule
    apres chaque modification (clic, Shift+clic, deselection, rectangle, lasso, cercle, boucle)
    et apres chaque operation d'edition, sur l'identite topologique SOUDEE.
    
    ARETES A COULEUR INTERPOLEE ('semi-selectionne' de Blender) : le batch de lignes portait
    deja une couleur PAR SOMMET (pos3+rgba4) -> le GPU interpole nativement, cout nul, un seul
    draw call, aucun decoupage en segments necessaire. Chaque extremite recoit SA couleur :
    un sommet selectionne teinte ses aretes incidentes en degrade (orange pres du sommet,
    noir a l'autre bout) ; sommet actif = blanc. Tri en 2 passes ajuste : les aretes ayant AU
    MOINS une extremite selectionnee passent en 2e passe pour gagner le z-fight.

```

 - **Ce qu'il fait** : Ce premier commit rends compte de l'ajout de trois nouvelle fonctionnalités (à cause du mot clé **feat**) : flushing de selection , les aretes a couleur interpolée et aussi à l'inmplémentation des overlay de l'interface utilisateur de Nkentseu.

 - **Pourquoi il le fait** : Il est fait pour corriger les bugs de Wireframe selon les angles, ainsi que le dessin conditionnel des triangles de débugage.

 - **Contient-il plusieurs sujets** : Oui ce commit contient plusieurs sujets. **3** environ. la modification dans l'implémntation de l'overlay, l'implémentation d'un flushing à la Blender et l'interpolation des couleurs.

## Analyse du second commit :

```
commit cabdcb38ca972ae1c6b73662b2c714c88c9253cb
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Mon Jul 27 21:09:26 2026 +0100

    feat(editmode): outils de selection facon Blender (boucle Alt+clic, rectangle, lasso, cercle)
    
    Moteur (NkEditMesh) :
    - GetEdgeLoop(a,b,...) : parcours 'tout droit' next(twin(next(h))) dans les deux sens,
      arret propre sur bord/n-gon.
    - GetFaceLoop(a,b,...) : anneau de faces via l'arete opposee.
    - Les deux comparent les aretes sur l'IDENTITE TOPOLOGIQUE SOUDEE (NkEmFindHedge) :
      ils ne fonctionnent que grace a la soudure precedente.
    
    Demo3D — coeur commun Demo3D_SelectInZone() parametre par un predicat de zone, partage
    par les 3 outils ecran ; respecte le mode actif (V=sommet, E=milieu d'arete, F=centre de
    face) et les modificateurs (Shift=ajouter, Ctrl=retirer), ignore les elements dos-camera
    hors X-ray, termine par Demo3D_NormalizeSel() :
    - B = rectangle (trace en pointilles, one-shot comme Blender)
    - Ctrl+glisser = lasso (contour fin, test point-dans-polygone par ray casting)
    - C = cercle modal (48 segments, molette = rayon, Echap/C = sortir)
    - Alt+clic = boucle d'aretes (sur arete) ou de faces (sur face) ; Shift+Alt = ajouter
    - HUD : ligne dediee avec les raccourcis + l'outil modal actif
    - Env de test : NK_SEL_LOOP=edge|face
    
    LIMITE CONNUE : sur un cube brut, les coins sont de valence 3 ou 'continuer tout droit'
    n'est pas defini -> la boucle derive (7 aretes au lieu de 4). Correct sur un maillage de
    quads reguliers. Regles de valence a affiner pour coller a Blender.
```

- **Ce qu'il fait** : Ce commit ajoute des outils de sélection blender like dans demo3D. 

-**Pourquoi ?** : Le commit n'explique pas pourquoi cette fontionnalité est ajouté dans le code. Il se contente de décrire ce qui a été fait chaque élément ajouté.

- **Porte t-il sur un seul sujet ?** : oui. Le seul sujet de ce commit est d'ajouter des outils de sélection dans le style belnder.

- Troisième commit :

```
commit 35d10cd42e36b4a77f4fe01af5301e07e4967d6f
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Mon Jul 27 20:19:49 2026 +0100

    fix(editmode): soudure topologique (loop cut fait le tour), selection vertex visible, gizmo ne bloque plus le clic
    
    SOUDURE TOPOLOGIQUE (correctif structurel) :
    - BuildVertexMerge() : grille de hachage spatiale O(n) -> identite topologique par position.
    - LinkTwins() apparie les demi-aretes jumelles sur cette identite -> topologie manifold.
    - Les attributs (normales, UV) restent portes par les COINS (modele Blender : maillage
      soude + attributs par loop) -> aucun lissage parasite, le cube garde ses facettes nettes.
    - Mesure : 24 -> 12 aretes uniques pour un cube. Loop cut 2 coupes -> 14 faces :
      l'ANNEAU FAIT LE TOUR (verifie en capture, la bande traverse le dessus et le cote).
    - Debloque aussi toutes les operations traversant les faces (boucles d'aretes, futur knife).
    
    BUG A (selection de sommet invisible) — cause reelle trouvee, ce n'etait PAS le toggle :
    le filtre facingCam combine aux sommets dupliques par face retenait au pick une copie
    tournant le dos a la camera ; elle passait bien en orange mais etait masquee par le filtre.
    Fix : Demo3D_NormalizeSel() + PropagateSelectionToCoincident() etendent la selection a
    toutes les copies coincidentes, et l'actif est recale sur la copie face camera.
    
    BUG B (gizmo bloquait la selection) : dans PickHandle, le disque central capturait tout
    clic dans son rayon avec un bonus de priorite. Desormais : petit disque central (<=18px)
    plein sans bonus ; grand cercle (rotation/vue) = COURONNE, seul le contour est pickable,
    l'interieur laisse passer le clic vers le maillage. Le drag en cours garde le clic.
```

- **Ce qu'il fait** : Ce commit rend compte grâce au mot clé **fix** que l'action effectuée ici est une correction de deux bugs de l'éditmode: la sélection de sommets invisibles, et le gizmo qui bloquait la sélection.

- **Pourquoi** : Le commit révèle deux raisons à la correction du Bug: 
- la première : le filtre facingCam combine aux sommets dupliques par face retenait au pick une copie tournant le dos a la camera, qui passait en orange mais était marqué par le filtre.
- la deuxième : dans PickHandle, le disque central capturait tout.

- **Porte t-il un sujet ?** : Oui il ne porte qu'un seul sujet, qui est la correction des Bug de l'éditmode.

## Réécriture du commit le plus faible

Réécriture du second commit.
> les modifications apportées sont surlignées dans le texte du commit


commit cabdcb38ca972ae1c6b73662b2c714c88c9253cb
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Mon Jul 27 21:09:26 2026 +0100

feat(editmode): outils de selection facon Blender (boucle Alt+clic, rectangle, lasso, cercle)
    
Moteur (NkEditMesh) :
- GetEdgeLoop(a,b,...) : parcours 'tout droit' next(twin(next(h))) dans les deux sens,
arret propre sur bord/n-gon.
- GetFaceLoop(a,b,...) : anneau de faces via l'arete opposee.
- Les deux comparent les aretes sur l'IDENTITE TOPOLOGIQUE SOUDEE (NkEmFindHedge) :
ils ne fonctionnent que grace a la soudure precedente.
    
Demo3D — coeur commun Demo3D_SelectInZone() parametre par un predicat de zone, partage    par les 3 outils ecran ; respecte le mode actif (V=sommet, E=milieu d'arete, F=centre de
face) et les modificateurs (Shift=ajouter, Ctrl=retirer), ignore les elements dos-camera
hors X-ray, termine par Demo3D_NormalizeSel() :
- B = rectangle (trace en pointilles, one-shot comme Blender)
- Ctrl+glisser = lasso (contour fin, test point-dans-polygone par ray casting)
- C = cercle modal (48 segments, molette = rayon, Echap/C = sortir)
- Alt+clic = boucle d'aretes (sur arete) ou de faces (sur face) ; Shift+Alt = ajouter
- HUD : ligne dediee avec les raccourcis + l'outil modal actif
- Env de test : NK_SEL_LOOP=edge|face
LIMITE CONNUE : sur un cube brut, les coins sont de valence 3 ou 'continuer tout droit'
n'est pas defini -> la boucle derive (7 aretes au lieu de 4). Correct sur un maillage de
quads reguliers. Regles de valence a affiner pour coller a Blender.

 `Les Mesh peuvent être maintenant édité suivant les 3 modes de selections présents depuis le NKEditMesh`
