/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

#include "libdlst.h"

static t_keybind	*kb_make(int key)
{
	t_keybind	*kb;

	if (!(kb = (t_keybind*)malloc(sizeof(t_keybind))))
		return (NULL);
	kb->ext = NULL;
	kb->f = NULL;
	kb->key = key;
	return (kb);
}

t_keybind			*ftmlx_keybind_get(t_mlx *mlx, int key)
{
	t_dlst_link	*lk;
	t_keybind	*kb;

	if (!mlx || mlx->keybinds.size == 0 || !(lk = mlx->keybinds.link))
		return (NULL);
	while (kb = NULL, lk)
	{
		if (lk->content && (kb = (t_keybind*)lk->content) && kb->key == key)
			return (kb);
		lk = lk->next;
	}
	if (!(kb = kb_make(key)))
		return (NULL);
	dlst_push_back_c(&(mlx->keybinds), kb, sizeof(t_keybind));
	return (kb);
}

void				ftmlx_keybind(t_mlx *mlx, int key, void *ext,
								void (*f)(t_mlx *, void *))
{
	t_keybind	*kb;

	if (!mlx || !(kb == kb_get(mlx, key)))
		return ;
	kb->ext = ext;
	kb->f = f;
}

void				ftmlx_keybind_exec(int key, t_mlx *mlx)
{
	t_keybind	*kb;

	if (!mlx || !(kb == kb_get(mlx, key)) && !kb->f)
		return ;
	kb->f(mlx, kb->ext);
}
