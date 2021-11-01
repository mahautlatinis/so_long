# So long 🐬

So long sera probablement votre premier projet graphique (avec la minilibX). C'est un bon exercice pour vous préparer pour cub3d. Les parsings sont similaires (mais celui de so_long est plus court/simple). Vous devrez uniquement gérer la vue 2D (top view). L'objectif est de récupérer tous les collectibles puis d'accéder au point de sortie "avec le moins de mouvements possibles". Nous devrons compter et afficher chaque mouvement. La difficulté se trouve principalement dans la découverte de la MLX.

![malatini](/screen.png)

#### https://harm-smits.github.io/42docs/libs/minilibx

## Textures
Pour créer vos propres textures (si vous n'en trouvez pas), vous devrez convertir des fichiers PNG en fichier XPM. Vous pouvez réaliser votre propre pixel art en utilisant notamment Aseprite qui est bien plus simple d'utilisation que Photoshop. Pensez a faire des PNG transparents ayant une taille de 32 par 32 pixels ou de 64 par 64 pixels. 

Une fois les fichiers xpm créés / trouvés, une fonction de la MLX vous permettra de les afficher. Si vous avez des problèmes de "performance" sur votre fenêtre, utilisez la fonction mlx_do_sync sous MAC OS ou cherchez comment éviter cela sur Linux (*voir code*).

## Tests à effectuer
 **Ajoutez -fsanitize=address -g au Makefile**
### Parsing
* Tester avec des 0 à la places des 1 sur les murs (haut, bas, côtés).
* Tester avec des char non autorisés dans le sujet.
* Tester avec des whitespaces.
* Tester avec plusieurs joueurs.
* Tester avec aucune sortie, aucun collectible.

### Arguments 
* Tester avec des maps dont l'extension n'est pas .ber
* Tester avec des fichiers qui n'existent pas
* Tester avec un dossier qui porterait une extension .ber
* Tester sans argument 
* Tester avec trop d'arguments

### Game play
* Les collectibles doivent disparaitre lorsqu'ils sont touchés.
* Il doit y avoir une "collision avec les murs". Comprenez que le player ne doit pas passer a travers. 
* Le player doit pouvoir sortir uniquement lorsque les collectibles ont tous été recupérés.

Credits to labintei et ttranche pour mes magnifiques textures 😘
