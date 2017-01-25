/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/08/09 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	philo_init(t_philosopher *p, int id)
{
	p->id = id;
	p->hp = MAX_LIFE;
	p->state = STATE_THINK;
	p->update_timer = THINK_T * ONE_SEC;
	time_init(&(p->time));
	g_env.sticks[id] = 0;
	pthread_create(&(p->thread), NULL, thread_main, p);
}

int		philo_update_hp(void)
{
	int		i;

	i = -1;
	//philo_show_health();
	while (++i < g_env.philosopher_count)
	{
		if (g_env.p[i].state != STATE_EAT)
			g_env.p[i].hp -= 1;
		if (g_env.p[i].hp <= 0)
		{
			ft_putchar('0' + g_env.p[i].id);
			ft_putstr("] DIED\n");
			g_env.is_running = 0;
			return (0);
		}
	}
	return (1);
}

void	philo_show_health(void)
{
	int		i;

	i = -1;
	while (++i < g_env.philosopher_count)
	{
		if (g_env.p[i].state == STATE_EAT)
			ft_putchar('!');
		ft_putnbr(g_env.p[i].hp);
		ft_putchar('(');
		ft_putchar('0' + g_env.sticks[g_env.p[i].id]);
		ft_putchar(')');
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

int		philo_count(int ac, char **av)
{
	int c;

	if (ac <= 1)
		return (PHILOSOPHER_COUNT);
	c = ft_atoi(av[1]);
	if (c >= 2 && c <= PHILOSOPHER_COUNT)
		return (c);
	return (PHILOSOPHER_COUNT);
}

void	philo_main_update(t_philosopher *p)
{
	if (update_timer(&(p->time), &(g_env.refresh_timer), ONE_10SEC))
	{
		sdl_update(&g_env.sdl);\
		philo_show_health();
	}
	if (update_timer(&(p->time), &(g_env.over_timer), 0))
	{
		ft_putendl(END_PHRASE);
		g_env.is_running = 0;
	}
	if (update_timer(&(p->time), &(g_env.update_timer), g_env.update_len))
	{
		ft_putnbr(g_env.over_timer / 1000);
		ft_putendl(" remaining seconds.");
		if (!(philo_update_hp()))
			g_env.is_running = 0;
	}
}
