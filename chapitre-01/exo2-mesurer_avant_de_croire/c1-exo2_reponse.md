# Reponse

## Nombre de projets:
Pour compter le nombre projets, la commande qui a été utilisé est `grep` 
- commande exécutée et résultats:

```bash
jenga info | grep -c "ConsoleApp"
```
resultat : **65**

```bash
jenga info | grep -c "WindowedApp"
```
resultat : 52

```bash
jenga info | grep -c "TestSuite"
```
resultat : 64

```bash
jenga info | grep -c "StaticLib"
```
resultat : 55

cela donne un total de : **236** projets, contre **221** dans le cours.

## Comptage du nombre de lignes

l'outil utilisé ici est **Cloc**, dans sa version **2.1.0**, et disponible sur 
[https://github.com/AlDanial/cloc/releases]

En exécutant la commande:

```shell
 C:\Users\Administrator\Downloads\cloc\cloc-2.10.exe . --exclude-dir=Build --match-f="\.(cpp|h)$"
```
dans le répertoire de nkentseu j'obtiens: le résultat suivant selon le tableeau suivant.

|Language | files | blank | comment | code
|---|---| ---|--- |--
|C++| 1439| 97179| 128314| 648993
|C/C++ Header| 2450| 104924| 307893| 531255
|SUM: | 3889| 202103| 436207| 1180248

- J'obtiens ainsi très exactement **1180248** lignes de code, contre **1193385** lignes de code d'après le cours;

- un nombre de fichiers de **3889**
dans le répertoire racine de nkentseu, contre **2 641** fichiers tel que précisé dans le cours.

Cette différence s'explique principalement par:
- la prise en compte des fichier en-tête;

- Des mise à jour régulières du dépôt via `git pull`, qui entraines des aujouts et des délétions des lignes de code dans les fichiers entêtes et sources

- l'abscence d'exemples d'applications ou encore de projet dans le dépot distant disponible sur github, mais présent sur la machine de l'encadrant.