/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:42:16 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/16 20:42:16 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <so_long.h>
#include <draw.h>

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
	i = 0;
	len = RESOLUTION_Y * image->line_length + RESOLUTION_X * (image->bits_per_pixel / 8);
	dst = image->img_address;
	while (i < len)
	{
		dst[i] = 100;
		i++;
	}
}

int	draw_frame_to_image(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->background.img_ptr, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_window, mlx->scene.pc.image.img_ptr, mlx->scene.player.x + 5, mlx->scene.player.y + 9);
//	redraw_window(mlx);
	return (1);
}