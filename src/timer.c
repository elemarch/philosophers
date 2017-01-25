/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/08/09 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	time_init(t_times *t)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	t->curr = time.tv_sec * 1000 + time.tv_usec / 1000;
	t->old = t->curr;
	t->diff = 0;
}

void	update_diff(t_times *t)
{
	struct timeval time;

	t->old = t->curr;
	gettimeofday(&time, NULL);
	t->curr = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (g_env.update_len == 500)
		t->diff = (t->curr - t->old) * 2;
	else if (g_env.update_len == 2000)
		t->diff = (t->curr - t->old) * 0.5;
	else
		t->diff = (t->curr - t->old);
}

int		update_timer(t_times *t, int *timer, int reload)
{
	if (*timer <= t->diff)
	{
		*timer = reload;
		return (1);
	}
	*timer = *timer - t->diff;
	return (0);
}
