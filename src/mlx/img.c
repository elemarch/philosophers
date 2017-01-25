/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ftmlx.h"
#include "libft.h"
#include "libdlst.h"

t_img	*img_make(t_mlx *mlx, int w, int h)
{
	t_img *i;

	if (!mlx->mlx || !(i = (t_img*)malloc(sizeof(t_img))) ||
		!(i->img = mlx_new_image(en->mlx, w, h)))
		return (0);
	i->width = w;
	i->height = h;
	i->data = mlx_get_data_addr(i->img, &i->bbp, &i->lsize, &i->end);
	i->bbp /= 8;
	i->mlx = mlx;
	return (i);
}

void	img_destroy(t_mlx *mlx, t_img **i)
{
	if (mlx && mlx->mlx && i && *i && (*i)->img)
	{
		mlx_destroy_image(mlx->mlx, (*i)->img);
		FREE(*i);
	}
}

void	img_load(t_mlx *mlx, char *fname, int id)
{
	t_img		*i;
	t_dlst_link	*lk;

	if (!fname || access(fname, F_OK) == -1 || !(i = img_make(mlx, 4, 4)))
	{
		ft_putmstr(fname, " file not found or could not be loaded.", "\n");
		return ;
	}
	if (!(lk = dlst_push_back_c(&(mlx->imglst), i, sizeof(t_img))))
		return ;
	mlx_destroy_image(mlx->mlx, i->img);
	i->img = mlx_xpm_file_to_image(mlx->mlx, fname, &i->width, &i->height);
	i->data = mlx_get_data_addr(i->img, &i->bbp, &i->lsize, &i->end);
	i->bbp /= 8;
	lk->content_size = id;
	mlx->imgs = (t_img**)dlst_to_array(&(mlx->imglst));
	return ;
}

void	img_display(t_mlx *mlx, size_t id, int x, int y)
{
	if (!mlx || mlx->imglst.size < id + 1)
		return ;
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->imgs[id], x, y);
}

char	*img_at(t_img *i, int x, int y)
{
	if (!i || x < 0 || x + 1 > i->height || y < 0 || y + 1 > i->width)
		return (NULL);
	return ((x * i->lsize) + (y * i->bbp));
}
