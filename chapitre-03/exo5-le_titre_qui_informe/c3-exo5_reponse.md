# REPONSE DE L'EXERCICE 5

>L'exercice 5 demande 3 tâches principales: Créer la fenêtre avec un titre du nom de celui du document (en l'occurence celui du dossier de l'exercice), l'ajout d'un astéris en cas de modification de la fenêtre, mais aussi la mise à jour contrôllée de la taille de la fenêtre affichée dans la barre de titre.

## Création de la fenêtre avec le titre demandé

Le titre choisi ici est celui du chapitre. Cette tâche est assurée par le bout de code:

```cpp
cfg.title       =   "exo5-le_titre_qui_informe";
```
dès le départ de la configuration de la fenêtre.

## Ajout de l'astérisque en cas de modification de la fenêtre

L'astérisque n'est pas fait au hasard. Il est géré par unevariable booléenne qui permet de détecter tous les évènements en rapport avec la fenêtre comme montré dans le bloc de code suivant:

```cpp
    math::NkVec2u size = window.GetSize();
    bool modified = false;

    while (window.IsOpen()) {
        while (NkEvent* e = NkEvents().PollEvent()) {
            if (e->Is<NkWindowCloseEvent>())
                window.Close();
            if (e->As<NkWindowMoveEvent>()) {
                modified = true;
                window.SetTitle("exo5-le_titre_qui_informe * " + window.GetSize().ToString());
            }
            if (e->Is<NkWindowResizeEndEvent>()) {
                size = window.GetSize();
                modified = true;
            }
            if (e->Is<NkWindowDpiEvent>()) modified = true;
            if (e->Is<NkWindowFocusGainedEvent>()) modified = true;
            if (e->Is<NkWindowPaintEvent>()) modified = true;
            if (e->Is<NkWindowShownEvent>()) modified = true;
            if (e->Is<NkWindowFocusLostEvent>()) modified = true;
            if (e->Is<NkWindowMoveEndEvent>()) modified = true;

            if (modified) {
                window.SetTitle("exo5-le_titre_qui_informe " + size.ToString() + "  * ");
            } else {
                window.SetTitle("exo5-le_titre_qui_informe " + size.ToString());
            }
            modified = false;
        }
    }
```

- **La gestion contrôlée de l'état de modification de la fenêtre** : Ici, la fenêtre est considérée comme modifiée lorsqu'elle reçoitun message d'évènement de type `NKWindowEvent`. La réception de ses messages entraine la modificatoin de la variable booléenne **modified** qui défini l'ajout de l'astérisque.

- **La msise à jour de la taille dans le titre** : La mise à jour de la taille dans le titre de la fenêtre ne se fait qu'à un seul moment, celuioù celle ci reçoit l'évènement de redimensionnement. La variable qui y est modifié est `size` de type `NKVecu`.
```cpp
if (e->Is<NkWindowResizeEndEvent>()) {
    size = window.GetSize();
    modified = true;
}
```
la variable size est ainsi réutilisé plus tard pour afficher en continue la taille courante dans la boucle de rendu, sans jamais avoir à questionner permanament la taille en interne de la fenêtre.
