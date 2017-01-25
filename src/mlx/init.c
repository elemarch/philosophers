/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

#include "utils.h"

void	ftmlx_setup_loop(t_mlx *mlx, void *var, void (*f)(void *))
{
	if (!mlx)
		return ;
	mlx->update_var = var;
	mlx->f_update = f;
}

void	ftmlx_setup_close(t_mlx *mlx, void *var, void (*f)(void *))
{
	if (!mlx)
		return ;
	mlx->close_var = var;
	mlx->f_close = f;
}

t_bool	ftmlx_init(t_mlx *mlx, int winw, int winh, char *wname)
{
	if (!mlx || !(mlx->mlx = mlx_init()))
		return (FALSE);
	if (!(mlx->mlx_win = mlx_new_window(mlx->mlx, winw, winh, wname)))
		return (FALSE);
	if (mlx->f_update)
		mlx_loop_hook(mlx->mlx, mlx->f_update, mlx->update_var);
	mlx_hook(mlx->mlx_win, 3, (1L << 1), &ftmlx_keybind_exec, mlx);
	if (mlx->f_close)
		mlx_loop_hook(mlx->mlx, mlx->f_close, mlx->close_var);
	mlx_do_sync(mlx->mlx);
}
