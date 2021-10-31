/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:41:15 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/28 16:25:07 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <mlx.h>
#include <so_long.h>
#include <events.h>
#include <draw.h>

int	kill(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_window);
	exit (0);
}

void	key_action_controls(t_scene *scene, t_key key_code, t_mlx *mlx)
{
	static t_bool	walk;

	if (key_code == RIGHT && scene->player.position.x < RESOLUTION_X - STEP)
		scene->player.speed.x += SPEED_STEP;
	else if (key_code == LEFT && scene->player.position.x > 0)
		scene->player.speed.x -= SPEED_STEP;
	else if (key_code == UP && scene->player.position.y > 0)
		scene->player.speed.y -= SPEED_STEP;
	else if (key_code == DOWN && scene->player.position.y < RESOLUTION_Y - STEP)
		scene->player.speed.y += SPEED_STEP;
	else if (key_code == PLUS && scene->background_fill < 255)
	{
		scene->background_fill += 5;
		init_background_image(mlx, &mlx->background);
	}
	else if (key_code == MIN && scene->background_fill > 0)
	{
		scene->background_fill -= 5;
		init_background_image(mlx, &mlx->background);
	}
	else
		return ;
	draw_frame_to_image(mlx);
}

int	keypress(t_key key_code, t_mlx *mlx)
{
	if (key_code == RIGHT || key_code == LEFT || key_code == UP || \
		key_code == DOWN || key_code == A || key_code == D || key_code == PLUS || key_code == MIN)
		key_action_controls(&mlx->scene, key_code, mlx);
//	else if (key_code == PLUS || key_code == MIN || key_code == B_SPACE || \
//		key_code == M || key_code == N || key_code == Z || key_code == F1 || \
//		key_code == F2)
//		key_action_settings(&mlx->scene, key_code);
//	else if (key_code == J || key_code == K || key_code == L || \
//		key_code == W || key_code == S || key_code == P)
//		key_action_colours(&mlx->scene, key_code);
	else if (key_code == ESC)
		kill(mlx);
	return (1);
}