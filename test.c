#include "so_long.h"

/*
** Fonction principale du programme So Long
** Initialise MLX, crée une fenêtre et affiche une image
*/
int ft_stop(t_data *data) // fermer la fenetre
{
	mlx_destroy_image(data->mlx_ptr, data->img_sol);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
	
	// free(data->img_sol);
	free(data->mlx_ptr);
	free(data);
    exit(0);
    return (1);
}

int key_hook(int key, t_data *data)
{
	(void)data;
    if (key == KEY_A)
        printf("bonjour");
    printf("key:%d\n", key);
    return (1);
}

int main(void)
{
	// ========== ÉTAPE 1: ALLOCATION MÉMOIRE ==========
	// Déclaration du pointeur pour la structure de données
	t_data *data;

	// Allouer la mémoire pour la structure
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);

	// ========== ÉTAPE 2: INITIALISATION MLX ==========
	// Initialiser la bibliothèque mlx
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free(data);
		return (1);
	}
    // data->map_x = 1000;
    // data->map_y = 1000;

	// ========== ÉTAPE 3: CRÉATION DE LA FENÊTRE ==========
	// Créer une nouvelle fenêtre (largeur: 800, hauteur: 600)
	data->win_ptr = mlx_new_window(data->mlx_ptr, 6 * 64, 3 * 64, "So Long");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (1);
	}

	// data->win_ptr2 = mlx_new_window(data->mlx_ptr, 400, 1200, "Woojeong");
	// if (!data->win_ptr2)
	// {
	// 	mlx_destroy_display(data->mlx_ptr);
	// 	free(data->mlx_ptr);
	// 	free(data);
	// 	return (1);
	// }

	data->img_height = 64;
	data->img_width = 64;
	// ========== ÉTAPE 4: CHARGEMENT DE L'IMAGE ==========
	// Charger une image et la placer dans la fenêtre
	// Assurez-vous de remplacer le chemin par un chemin d'image valide
	data->img_path = "./image/mur.xpm";
	data->img_sol = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path, &data->img_width, &data->img_height);
	if (!data->img_sol)
	{
		perror("Échec du chargement de l'image");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (1);
	}

	// ========== ÉTAPE 5: AFFICHAGE ==========
	// Placer l'image dans la fenêtre (position x: 100, y: 50)
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_sol, data->img_height * 5 , data->img_width * 2);


	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_sol, 444 , 50);

	// Afficher un message dans la fenêtre (position x: 10, y: 10, couleur: blanc)
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xBAD1C5, "J'ai passe pipex ~~~~~!!!!");

	// ========== ÉTAPE 6: GESTION DES ÉVÉNEMENTS ==========
	// Gérer les événements de la fenêtre (fermeture, touches, etc.)
	mlx_hook(data->win_ptr, DestroyNotify, 0, ft_stop, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_hook, data);

	// ========== ÉTAPE 7: BOUCLE D'ÉVÉNEMENTS ==========
	// Démarrer la boucle d'événements (le programme reste ouvert)
	mlx_loop(data->mlx_ptr);

	return (0);
}
