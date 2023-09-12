// parsing pour interpreter les maps
// faire l'affichage de la map avec la mlx
// realiser les motifs 2d murs plafond sol
// realiser l'affichage des motifs sur les murs (texture)
// realiser les actions, deplacements

// chaque rayons par d'une ligne d'epaule du joueur (pour eviter l'effet fish eye)
// a chaque x distance, il verifie s'il est dans le mur par rapport a X la position du joueur et la coorodonnee du mur, si c'est le cas, fin de la boucle on passe au dessin du mur.
// la hauteur du mur sera en fonction de la distance pour donner l'effet de perspective.

// posX posY = coordonnees de position du joueur
// dirX dirY = direction dans laquelle regarde le perso
// planX planY = camera joueur -1 a gauche 0 au milieu et 1 a droite
// mapX mapY = represent le carre dans lequel se trouve le ray (pour eviter les murs invisibles)

// si le joueur pivote le pos ne bouge pas.
// si le joueur avance droit devant lui le dir ne bouge pas
// si quelque chose bouge dans le champ de vision, plan ne change pas

// time et oldTime serve a changer l'affichage en "temps reel" et peut servir a calculer un FPS