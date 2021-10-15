/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:19:35 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/15 23:42:42 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <so_long.h>
#include <draw.h>
#include <events.h>

#include <stdio.h>



void	init_default_scene(t_scene *scene)
{
	scene->res.x = RESOLUTION_X;
	scene->res.y = RESOLUTION_Y;
	scene->pc.file = "walk1.xpm";
	scene->player.x = 0;
	scene->player.y = 0;
}

void	hook_to_mlx(t_mlx *mlx)
{
	mlx_hook(mlx->mlx_window, KEY_RELEASE, \
			(1L << KEY_RELEASE_MASK), keypress, mlx);
	mlx_hook(mlx->mlx_window, DESTROY_NOTIFY, \
			(1L << STRUCTURE_NOTIFY_MASK), kill, mlx);
//	mlx_hook(mlx->mlx_window, BUTTON_PRESS, \
//		(1L << BUTTON_PRESS_MASK), mouse_button, mlx);
//	mlx_hook(mlx->mlx_window, MOTION_NOTIFY, \
//		(1L << POINTER_MOTION_MASK), mouse_move, mlx);
//	mlx_loop_hook(mlx->mlx_ptr, draw_frame_to_image, mlx);
}

void	init_mlx(t_mlx *mlx, const t_scene *scene)
{
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_window = mlx_new_window(mlx->mlx_ptr, scene->res.x, \
		scene->res.y, PROJECT);
}

void	init_mlx_image(t_mlx *mlx, t_img_data *image, t_sprite *sprite)
{

	image->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, sprite->file, &sprite->size.x, &sprite->size.y);
	printf("x->%d\ny->%d", sprite->size.x, sprite->size.y);
	image->img_address = mlx_get_data_addr(image->img_ptr, \
		&image->bits_per_pixel, &image->line_length, &image->endian);
}

int	main(void)
{
	static t_mlx mlx;
//	t_bool_err parse_success;

	init_default_scene(&mlx.scene);
	init_mlx(&mlx, &mlx.scene);
	init_background_image(&mlx, &mlx.background);
	init_mlx_image(&mlx, &mlx.scene.pc.image, &mlx.scene.pc);
	hook_to_mlx(&mlx);
	draw_frame_to_image(&mlx);
	mlx_loop(mlx.mlx_ptr);
}