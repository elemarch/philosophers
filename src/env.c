/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/08/09 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		env_init(int count)
{
	int	i;

	g_env.pause = 0;
	g_env.time.curr = time(NULL);
	g_env.over_timer = TIMEOUT * ONE_SEC;
	g_env.update_len = ONE_SEC;
	g_env.refresh_timer = ONE_10SEC;
	g_env.update_timer = g_env.update_len;
	g_env.philosopher_count = count;
	sdl_init(&(g_env.sdl));
	pthread_mutex_init(&g_lock, NULL);
	time_init(&(g_env.time));
	g_env.updates[STATE_EAT] = thread_eat;
	g_env.updates[STATE_SLEEP] = thread_sleep;
	g_env.updates[STATE_THINK] = thread_think;
	g_env.updates[STATE_WAIT] = thread_wait;
	g_env.is_running = 1;
	i = -1;
	while (++i < g_env.philosopher_count)
		philo_init(&(g_env.p[i]), i);
}

void		env_stop(void)
{
	int i;

	i = 0;
	while (++i < g_env.philosopher_count)
	{
		ft_putchar('0' + g_env.p[i].id);
		ft_putstr("] hp = ");
		ft_putnbr(g_env.p[i].hp);
		ft_putchar('\n');
		pthread_detach(g_env.p[i].thread);
	}
	ft_putstr("1\n");
	pthread_mutex_lock(&g_lock);
	ft_putstr("2\n");
	pthread_mutex_unlock(&g_lock);
	ft_putstr("3\n");
	pthread_mutex_destroy(&g_lock);
	ft_putstr("4\n");
}
