/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

#include "libdlst.h"

void	ftmlx_lstdelimg(t_img *img, size_t sz)
{
	sz = 0;
	if (!img || sz > 0 || !img->mlx)
		return ;
	mlx_destroy_image(img->mlx, img->img);
}

void	ftmlx_cleanup(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->spriteslst.size > 0)
		dlst_clear(&(mlx->spriteslst));
	if (mlx->keybinds.size > 0)
		dlst_fclear(&(mlx->spriteslst), ftmlx_lstdelimg);
	mlx->sprites = NULL;
}
