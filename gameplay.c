#include "so_long.h"

static void game_evebts(int keycode, t_game *game)
{
    if(keycode == KEY_W )
    {
        game->y_player -= 1;//w yani y değeri 1 azalır
        player_w(game);
    }
    else if(keycode == KEY_S)// s yani y derğeri 1 artar
    {
        game->y_player += 1;
        player_s(game);
    }
    else if(keycode == KEY_D) //d yani x artar
    {
        game->x_player += 1;
        player_d(game);   
    }
    else if(keycode == KEY_A)
    {
        game->x_player -= 1;
        player_a(game);
    }

}
static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)  // esc ve q ya basınca ekranı kapatır ve oyundan çıkar
		exit_game(game);
	else if (!game->endgame) // oyun sonlanmadıysa !0 = 1 içeri girer.
	{
		game_events(keycode, game);
		printf("Moves: %d\n", game->moves);
	}
	return (0);
}
void	gameplay(t_game *game) //mlx_hook eventları yakalar. Event geldiğinde onu ilgili fonksiyona yönlendirir.
{
	mlx_hook(game->win, 2, 0, keypress, game);  // eventları yakalamaya yarayan fonksiyon ON_KEYDOWN = 2 tuşa basıldığını gösterir. tuşu aşağı ittiğimiz için.
	mlx_hook(game->win, 17, 0, exit_game, game); // 0 maskeleme için ama bizim kütüphanede bu kısım desteklenmiyor o yüzden kullanmayıp 0 veriyoruz. ON_DESTROY = 17 pencerenin sol üst kçşesindeki x ya basıldığında iletilir.  
	mlx_hook(game->win, 12, 0, map_draw, game); // ON_EXPOSE = 12 (açığa çıkarmak). Oyunu yeniden çizmek için gerekli event.
}