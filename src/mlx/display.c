/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

#include "utils.h"

void	ftmlx_display_background(t_mlx *mlx, int imgid, t_bool repeat)
{
	int		x;
	int		y;
	t_img	*img;

	if (!mlx || mlx->imglst.size < imgid + 1 || !mlx->imgs ||
		!(img == mlx->imgs[imgid]))
		return ;
	if (!repeat)
	{
		img_display(mlx, id, x, y);
		return ;
	}
	x = 0;
	while (y = 0, x < mlx->win_height)
	{
		while (y < mlx->win_width)
		{
			img_display(mlx, id, x, y);
			y += img->width;
		}
		x += img->height;
	}
}

void	ftmlx_display_update(t_mlx *mlx)
{
	if (!mlx)
		return ;
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
 }
