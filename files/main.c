/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:07:17 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 17:24:05 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int add;

	add = 0;
	initvars();
	g_mlx_id = mlx_init();
	if (!initialize_game(argc, argv))
		return (0);
	g_win_id = mlx_new_window(g_mlx_id, g_width, g_height, "Cub3D");
	g_img_id = mlx_new_image(g_mlx_id, g_width, g_height);
	g_pixels = (int *)mlx_get_data_addr(g_img_id, &add, &add, &add);
	mlx_hook(g_win_id, 2, (1L << 1), onclicklistener, (void *)0);
	mlx_hook(g_win_id, 17, 0, clickdetecter, (void *)0);
	vision();
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7) == 1)
		return (savebitmap(g_width, g_height, g_pixels));
	mlx_put_image_to_window(g_mlx_id, g_win_id, g_img_id, 0, 0);
	mlx_loop(g_mlx_id);
	return (1);
}
