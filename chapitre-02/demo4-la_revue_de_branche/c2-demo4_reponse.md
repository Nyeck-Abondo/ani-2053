# REPONSE DE LA DEMO 4

> L"exercice de la démonstration 4 a été exécuté avec deux étudiants en me comptant: moi NYECK ABONDO et NOUMSSI TIATSAP VANESSA PRISCA. faute de camarades disponibles pour terminer le sprint.

## Projet mis en place

Le projet mis en place est celui d'une simple calculatrice moderne testée en console. le dépôt utilisé est celui de l'étudiante Noumssi, du nom de **MonEssai** vérifiable à l'URL .

Le dépôt du projet a été configuré sur github pour rendre obligatoire les pull request avant toute poussées ou fusion de modifications sur la branche principale du dpôt distant.

## Les règles du dépôts respectée :

- pour chaque nouvelles fonctionnalitées, une branche spécifique était créée. tel que montré ci dessous:



- Toute fusion sur la branche principale passait obligatoirement par une pull request qui devait être validée par au moins une personne du groupe. Tel qu'indiqué sur l'image ci desosus.

<img src="image.png" width = 100%>

- Toujours pull avant de soumettre ses modifications.

## Echange des branches

Les branches utilisées dans le dépôt commun étaient celles fournies par la commande suivante :
```
git branch -a

feature-calcul
feature-multiplication
feature-soustraction
fix-calcul
* main
remotes/origin/HEAD -> origin/main
remotes/origin/feature-add
remotes/origin/feature-add-sous
```

Celle de la collaboratrice se trouvant juste en dessous de la branche main.

- **Etude de la branche `feature-add`** :
    - **Ce que la branche fait** : D'après le nom de la branche et en se basant sur l'objectif du dépôt qui est de créer un calculatrice en console, cette branche a pour rôle l'implémentation de la fonctionnalité d'addition de la calculatrice.

    - **Analyse des commits** : En observant les commits via la commande `git log`, on obtien l'historique des commits de la collaboratrice.

    ```
    git log

    commit 883359578279cc34674d285b19ee8c07d0ccdde1 (HEAD -> main, origin/main, origin/HEAD)
    Merge: 423d435 ca1909a
    Author: noumssiprisca6-star <noumssiprisca6@gmail.com>
    Date:   Mon Sep 21 11:44:31 2026 +0200

        Merge pull request #6 from noumssiprisca6-star/feature-multiplication
        
        feat: Ajout de la multiplication par types simples.
    :...skipping...
    .
    .
    .
    .
    commit 663a359dc18dc71c253a2fc27b9b4f97ca70fbb8 (origin/feature-add)
    Author: noumssiprisca6-star <noumssiprisca6@gmail.com>
    Date:   Mon Sep 21 11:18:45 2026 +0200

        feat :la calculatrice .cpp
        apres la declaration  des fonction , il faut desormais les implementer d'ou la presence de ce fichier pour inserer de nouvelle fonctionnalire de calcul

    .
    .
    ```
    Le seul commit qui sera étudier sera donc celui au hash **663a359dc18dc71c253a2fc27b9b4f97ca70fbb8**, qui correspond à l'unique commit de la branche.

    - **La lisibilité** : Le commit est totalement lisible. Il n'expose son sujet, qui ici est la modification du fichier calculatrice.cpp. toutefois, il explique parfaitement le pourquoi de cette modification en disant qu'elle constitue la prochaine étape d'insertion de la fonctionnalité de calcul.

    - **Ce qui manque** : un sujet lisible. Le sujet du commit ne s'identifie qu'après lecture totale de son corps.


## Bilan des discussions

- **Point d'accord**: Les pull request devaient être traitées avant une durée de trente minutes après leur ouverture.
- **Descisions prises** : 
    - Validation de la fusion de la branche, après correction des éléments bloquant.
    - Création d'une branche spécifique pour chaque fonctionnalités distinctes, comme indique par le log en console suivant :
    ```
    git branch -a

    feature-calcul
    feature-multiplication
    feature-soustraction
    fix-calcul
    * main
    remotes/origin/HEAD -> origin/main
    remotes/origin/feature-add
    remotes/origin/feature-add-sous
    ```

