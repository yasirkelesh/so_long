#include "so_long.h"
static void img_init(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image
		(game->mlx, "assets/images/0.xpm", &game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "assets/images/1.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/images/PD.xpm", &game->img_w, &game->img_h);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, "assets/images/C.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "assets/images/E1.xpm", &game->img_w, &game->img_h);
}
static void size_window_init(t_game *game)
{
    int i;
    game->map_w = ft_strlen(game->map[0])*32;//map genişliği yani satırdaki elaman saysı * 32(kutucuğun boyutu)
    i = 0;
    while(game -> map[i] != NULL)
        i++;
        game->map_h = i *32; // map uzunluğu sütundaki  elman sayusu * 32
}   
void game_init(t_game *game)
{
    game->mlx = mlx_init();// software ve display arası bağlantı kuruyor. mlx bağlantı tanımlayıcıdır.
    size_window_init(game);
    game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
    game->moves = 0;// hareket sayısı nı sıfırdan başlatır
    game->endgame = 0;// ketprees fonksiyonu oyunn bittimi kontrol edecek 0 ise bitmedi 1 ise bitti.
    img_init(game);
    map_draw(game); // haritayı oluşturur.   
}