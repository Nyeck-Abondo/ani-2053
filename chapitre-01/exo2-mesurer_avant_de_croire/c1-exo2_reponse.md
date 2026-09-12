# Reponse

En exécutant la commande:
```shell
 dir -Recurse -Include *.cpp,*.h -File | Where-Object { $_.FullName -notmatch "\\build\\" } | Get-Content | Measure-Object -Line 
```
dans le répertoire de nkentseu j'obtiens: **1 623 115** lignes, contre **1 193 385** lignes tel que présenté dans le cours.

Dans un second temps en exécutant la commande : 
```shell
(Get-ChildItem -Recurse -Filter *.cpp -File).Count + (Get-ChildItem -Recurse -Filter *.h -File).Count
```
dans le répertoire racine de nkentseu on obtient: **3946** Fichiers, contre **2 641** fichiers tel que précisé dans le cours.

Cette différence s'explique principalement pas la prise en compte des fichier en-tête, des mise à jour régulières du dépôt via `git pull`m mais aussi par la présence dans le dossier application du Framework de projets personnels développés avec NkCanvas. ce qui justifie cet écart avec les chiffres du cours.