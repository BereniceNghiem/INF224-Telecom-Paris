## Bérénice Nghiêm

Projet C++/JavaSwing :
le but de ce TP est de créer l'ébauche du logiciel d'une set-top box multimédia permettant de jouer des vidéos, des films, d'afficher des photos, etc.

# Partie C++

Pour distinguer la partie sérialisation, on utilise dans le main :
#define VERSION_ETAPE_11
#ifdef VERSION_ETAPE_11 
Pour tester les autres étapes, on crée des fonctions test.

Réponses aux questions
## Etape 4
C'est une méthode virtuelle pure. Elle n'a pas d'implémentation dans la classe de base.
On peut les déclarer comme suit :
virtual void play() const = 0;
Une classe contenant au moins une méthode virtuelle pure devient une classe abstraite. Or, une classe abstraite ne peut pas être instanciée directement en C++.

## Etape 5
La propriété caractéristique qui permet de traiter différents types d'objets dérivés de la même manière est le polymorphisme.
Pour permettre le polymorphisme :
- la méthode dans la classe de base doit être déclarée comme virtuelle,
- les classes dérivées doivent redéfinir ces méthodes avec la même signature en utilisant le mot-clé override,
- utiliser des pointeurs ou des références à la classe de base.
Les éléments du tableau doivent être des pointeurs vers les objets.

## Etape 7
Afin qu'il n'y ait de fuite mémoire, il faut modifier les classes suivantes : multimedia, photo, video, film.
La copie par défaut peut poser problème lorsqu'elle copie uniquement l'adresse du pointeur.
Des solutions possibles sont :
1) désactiver la copie et l'affectation,
2) implémenter le "Rule of Three" - pour permettre la copie d'objets, on implémente le constructeur de copie, l'opérateur d'affectation et un destructeur.

## Etape 8
La liste de pointeurs d'objets permet d'éviter les copies coûteuses, car les pointeurs ne stockent qu'une référence à l'objet existant. 
De plus, la durée de vie des objets peut être gérée indépendamment de leur appartenance à un groupe.
En java, la mémoire est gérée de façon automatique. Et, lorsqu'un objet est ajouté à une liste, c'est une référence à cet objet qui est ajoutée. 
Il n'y a donc pas besoin de créer une liste de pointeurs.


# Partie Java/Swing

## Etape 1
Après avoir cliqué sur les boutons et redimensionné la fenêtre, on constate un souci.
Avant le redimensionnement : Chaque clic sur les boutons Ajouter ligne 1 et Ajouter ligne 2 ajoute une ligne de texte dans la zone de texte.
Après le redimensionnement : Si la zone de texte n'a pas d'ascenseurs (JScrollPane), les lignes ajoutées peuvent dépasser les limites visibles de la fenêtre et être partiellement cachées.
Avec JScrollPane (comme dans ton code) : Les barres de défilement apparaissent automatiquement, permettant de naviguer dans le contenu si la fenêtre est trop petite.
C'est précisément pour éviter la perte de visibilité du texte ajouté qu'on utilise un JScrollPane autour du JTextArea.
