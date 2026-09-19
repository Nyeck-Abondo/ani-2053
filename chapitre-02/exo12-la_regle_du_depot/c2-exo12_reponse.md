# REPONSE DE L'EXERCICE 12

Ici, nous rédigerons les règle git pour un projet collaboratif entre 4 étudiants.

## Le nomma des branches

Le nommage des branches dans un projet git utilise une convention qui retient trois noms principaux:

- **feature** c'est le nom des branches destinées au développement de nouvelles fonctionalitées.

- **release** : Ce nom de branche est destiné à la préparation de version distribuable du projet.

- **hotfix** : Ce nom de branche est destiné à celle traitant de correctifs urgents

## Le contenu d'un commit

un commit doit être divisé en 4 principales partie obéissant à des règles:

- **La ligne de sujet** : Elle doit être courte et présenter globalement ce que le commit apporte au dépôt. un commit n'a qu'un seul sujet et pas plus.

- **une ligne vide** : c'est tout simplement un saut de ligne après la ligne de sujet.

- **Le pourquoi** : c'est la troisième partie. elle est écrite après la ligne vide. C'est un paragraphe explicatif des choix qui ont amené à l'exécution du sujet traité par le commit.

- **L'impact du changement apporté par le commit sur le projet** : il dit dans la ligne après la justification ce que le commit a apporté dans le projet.

## Qui relit quoi ?

Dans un dépôt que quatre personnes partagent, une certaine disciple doit impérative reigner. En supposant le nom des étudiants A, B , C et D: 

- la poussé du travail sur le dépôt distant par l'étudiant A passe d'abord par la création d'une **pull request**, qui ne peuvent être validée que par les étudiant B et C au moins.

- Lors de la validation du code de A, l'étudiant B ou C qui relit doit tester le code en local et vérifier l'absence de bugs majeurs

## Ce qui est interdit

- Merger une branhe sans effectuer de **pull request pour vérifier le travail;

- Travailler directement sur la branche principale

- Valider une modification sans la tester localement au préalable

- supprimer des commits avec `git reset --hard` et utiliser `git push --force`. Cela modifie totalement l'historique de commit des collaborateurs;

- Valider sa propre **pull request**. Ce travail doit être exécuté par un autre memebre de l'équipe.

## Ce qu'on doit faire quand on casse la branche principale

Lorsqu l'on casse la branche principal, il fuat premièrement: 
- identifier le commit responsable en remontant le graphe de l'historique grace à `git log --graph` et noter son hash.

- revenir au dernier commit décrivant un état fonctionnel de celle ci en annulant celui qui a causé cette situation `git revert <hash du commit>`.

- Pousser les modifications sur le dépôt distant avec un `git push`