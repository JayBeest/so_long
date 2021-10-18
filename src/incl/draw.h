/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:41:58 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/16 20:41:58 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

int		draw_frame_to_image(t_mlx *mlx);
void	put_pixel(t_img_data *image, t_position position, unsigned int colour);
void	init_background_image(t_mlx *mlx, t_img_data *image);

#endif
