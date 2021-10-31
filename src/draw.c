/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:42:16 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/28 22:07:08 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>
#include <draw.h>
#include <unistd.h>

#include <stdio.h>

#include <stdio.h>

void	put_pixel(t_img_data *image, t_position position, unsigned int colour)
{
	char	*pixel_address;
	int		offset;

	offset = position.y * image->line_length + position.x * \
		(image->bits_per_pixel / 8);
	pixel_address = image->img_address + offset;
	*(unsigned int *)pixel_address = colour;
}

void	init_background_image(t_mlx *mlx, t_img_data *image)
{
	char	*dst;
	int		i;
	int		len;

	image->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->scene.res.x, mlx->scene.res.y);
	image->img_address = mlx_get_data_addr(image->img_ptr, \
		&image->bits_per_pixel, &image->line_length, &image->endian);
	printf("background_image_address = %p\n", image->img_address);
	i = 0;
	len = RESOLUTION_Y * image->line_length;
	printf("background_image_lebn= %d\n", len);
	dst = image->img_address;
	while (i < len)
	{
		dst[i] = mlx->scene.background_fill;
		i++;
		i++;
		dst[i] = 16;
		i++;
	}
}

void	bounce_spidey(t_movement *movement)
{
	t_position	*pos;

	pos = &movement->position;
	if (pos->x + movement->speed.x > RESOLUTION_X - STEP || pos->x + movement->speed.x < -10)
		movement->speed.x *= -1;
	pos->x = pos->x + movement->speed.x;
	if (pos->y + movement->speed.y > RESOLUTION_Y - STEP || pos->y + movement->speed.y < -10 || (movement->speed.y < 0 && movement->speed.y / movement->accel > -0.2))
		movement->speed.y *= -1;
	else if (movement->speed.y > 0)
		movement->speed.y *= movement->accel;
	else
		movement->speed.y /= movement->accel;
//	printf("speed.y = %f\n", movement->speed.y);
	pos->y = pos->y + movement->speed.y;
}

void	add_menu(t_mlx *mlx)
{
	char speedx[50];
	char speedy[50];

	sprintf(speedx, "Speed x: %f", mlx->scene.player.speed.x);
	sprintf(speedy, "Speed y: %f", mlx->scene.player.speed.y);
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, RESOLUTION_X - 250, 20, 0xffffff, speedx);
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, RESOLUTION_X - 250, 50, 0xffffff, speedy);
}

int	draw_frame_to_image(t_mlx *mlx)
{
	static int i;

	usleep(16666/2);
	i++;
	bounce_spidey(&mlx->scene.player);
//	if (i % 2)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->background.img_ptr, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->scene.pc.image.img_ptr, mlx->scene.player.position.x + 5, mlx->scene.player.position.y + 9);
	add_menu(mlx);
	return (1);
}