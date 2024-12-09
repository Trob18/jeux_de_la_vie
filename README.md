# Livrable POO

**Lien du GitHub :** https://github.com/Trob18/jeux_de_la_vie.git


# _Document technique pour utilisateur_ : 

### Qu'est ce que le jeu de la vie ?
Le jeu de la vie est un automate cellulaire créé par John Horton Conwayn, un mathématicien en 1970. Cet automate décrit l'évolution de cellules sur une grille selon des règles fixées.

### Quelles sont les règles ?

Une cellule peut avoir 3 états : **vivante**, **morte** ou **obstacle**.

La simulation se base sur 3 règles simples : 
-    **Naissance** : Une cellule morte entourée d'exactement 3 voisins vivants devient vivante.
-    **Mort** : Une cellule vivante meurt par sous-population (moins de 2 voisins vivants) ou par surpopulation (plus de 3 voisins vivants)
-    **Stabilité** : Une cellule morte qui ne respecte pas les conditions de naissance reste morte, une cellule vivante qui ne respecte pas les conditions de mort reste vivante.
`
### Comment simuler le jeu de la vie ?
Si vous voulez simuler le jeu de la vie, il vous suffit de respecter quelques pré-requis ainsi que de suivre les étapes qui vont suivre : 

Pré requis : 
- Compilateur C++ 17 ou supérieur
- Bibliothèque SFML
- Git 

--- 

:ballot_box_with_check: Etape 1 : Cloner notre repository github à l'aide de cette commande :
`git clone https://github.com/Trob18/jeux_de_la_vie.git`

---

:ballot_box_with_check: Etape 2 : Changer de répertoire à l'aide de la commande :
`cd jeux_de_la_vie`

---
:ballot_box_with_check: Etape 3 : Compiler le code avec la commande : 
`make`

---
:ballot_box_with_check: Etape 4 : Lancer l'exécutable avec la commande :
`jeu`

---
:ballot_box_with_check: Etape 5 : Création d'un fichier consommable avec les dimensions de votre grille ainsi qu'un 0 pour une cellule morte ou un 1 pour une cellule vivante. 
Vous pouvez le faire via votre terminal avec la commande :
`touch <nom_fichier_arbitraire>.txt`
Exemple de ce qui est attendu dans votre fichier : 

10 10
0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0


---

Une fois ces étapes réalisées, vous devrez fournir le nom de votre fichier consommable :warning:sans extension:warning:.

C'est à ce moment que vous devrez choisir entre nos deux modes de simulation : 
1. Le **mode console** : Dans ce mode, la simulation s'effectuera dans la console. Chaque itération sera automatiquement sauvegardée dans un document texte nommé `<nom_fichier_entree>_out`
2. Le **mode graphique** : Dans ce mode, la simulation s'effectuera dans une interface graphique.


Nous avons mis un place un système de gestion de la durée entre deux itérations :

-    `Appui sur la flèche du haut` : Augmentation de la vitesse.
-    `Appui sur la flèche du bas` : Diminution de la vitesse.




# _Présentation du code_ : 

Le code est séparé en plusieurs blocs de fonctions qui dépendent les uns des autres.

* **Traitement du fichier d'entrée**
En premier lieu, nous avons les fonctions pour traiter le fichier d'entrée. Celles-ci récupèrent chaque donnée du fichier d'entrée et attribuent ces données à des variables, par exemple la hauteur et la largeur de la matrice ainsi que l'état de chaque cellule sur la grille.
Cette fonction appelle une méthode de la classe Grille afin d'initialiser la grille en fonction des dimensions (hauteur et largeur).
Ensuite, elle fait appel à la génération des cellules de la classe Grille afin de construire la matrice initiale.
Le fichier est ensuite fermé pour ne conserver que les nouveaux attributs utiles au programme.
La simulation est alors lancée. Elle demande à l'utilisateur de choisir le mode qu'il souhaite activer.

* **Mode console**
Le mode console commence par construire un objet Vue_Console, qui utilise sa méthode afficher pour afficher la matrice initiale dans la console. Ensuite, ce mode appelle la méthode nouvGrille de la classe Grille, qui copie la matrice initiale et applique les règles du jeu de la vie sur chaque cellule de la matrice.
Il appelle également une méthode similaire pour initialiser des cellules obstacles. Ces cellules, bien qu'inactives pour influencer les cellules suivantes, restent présentes pendant toute la simulation.
Le programme appelle ensuite la fonction d'affichage de Vue_Console afin d'afficher la nouvelle matrice. Si la matrice d'obstacles contient une cellule, elle affiche :
    * 0 ou 1 pour les cellules normales,
    * 2 pour les cellules obstacles.

    Chaque itération est ensuite sauvegardée dans un fichier ".txt" fourni en sortie du programme.

* **Mode graphique**
Le mode graphique commence également par créer un objet, cette fois un objet de la classe Vue_Graphique. Ensuite, les mêmes méthodes sont appliquées pour obtenir une nouvelle matrice, après application des règles du jeu de la vie, ainsi qu'une matrice contenant les obstacles.
Le programme appelle alors la méthode d'affichage du mode graphique pour créer une fenêtre graphique représentant la grille. Cette fenêtre se charge d'ajouter des cellules d'une certaine dimension sur la grille initialisée :
    * Les cellules vivantes sont affichées en bleu,
    * Les cellules obstacles en vert,
    * Les cellules mortes en noir, afin de bien les différencier.
    
    En parallèle, le programme gère une méthode permettant de modifier manuellement le temps entre chaque itération pendant la simulation. Le joueur peut appuyer sur :
        * La flèche du haut pour augmenter le temps,
        * La flèche du bas pour le réduire.





























