Etape 1

Que constate-t-on après avoir cliqué sur les boutons et redimensionné la fenêtre ?

Avant le redimensionnement : Chaque clic sur les boutons Ajouter ligne 1 et Ajouter ligne 2 ajoute une ligne de texte dans la zone de texte.
Après le redimensionnement : Si la zone de texte n'a pas d'ascenseurs (JScrollPane), les lignes ajoutées peuvent dépasser les limites visibles de la fenêtre et être partiellement cachées.
Avec JScrollPane (comme dans ton code) : Les barres de défilement apparaissent automatiquement, permettant de naviguer dans le contenu si la fenêtre est trop petite.

C'est précisément pour éviter la perte de visibilité du texte ajouté qu'on utilise un JScrollPane autour du JTextArea.