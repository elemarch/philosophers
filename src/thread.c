/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/08/09 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		key_mgr(SDLKey key);

void		*thread_main(void *data)
{
	t_philosopher	*p;
	void			(*f)(t_philosopher*);

	p = (t_philosopher*)data;
	while (g_env.is_running)
	{
		SDL_PollEvent(&(g_env.sdl.event));
		if (KEYDOWN && !key_mgr(g_env.sdl.event.key.keysym.sym))
		{
			g_env.is_running = 0;
			break ;
		}
		update_diff(&(p->time));
		if (g_env.pause != 0)
			continue ;
		p->update_timer -= p->time.diff;
		f = g_env.updates[p->state];
		f(p);
		if (p->id == 0)
			philo_main_update(p);
	}
	return (NULL);
}

void		thread_eat(t_philosopher *p)
{
	if (p->update_timer > 0)
		return ;
	g_env.sticks[p->id] = 0;
	g_env.sticks[NEXT_STICK(p->id)] = 0;
	p->hp = MAX_LIFE;
	p->state = STATE_SLEEP;
	p->update_timer = SLEEP_T * ONE_SEC;
}

void		thread_sleep(t_philosopher *p)
{
	if (p->update_timer > 0)
		return ;
	if (g_env.sticks[p->id] == 0)
	{
		p->update_timer = THINK_T * ONE_SEC;
		p->state = STATE_THINK;
	}
	else
		p->state = STATE_WAIT;
}

void		thread_think(t_philosopher *p)
{
	if (p->update_timer <= 0 || g_env.sticks[p->id] != 0)
		p->state = STATE_WAIT;
}

void		thread_wait(t_philosopher *p)
{
	if (g_env.sticks[p->id] == 0 && g_env.sticks[NEXT_STICK(p->id)] == 0)
	{
		pthread_mutex_lock(&g_lock);
		if (g_env.sticks[p->id] == 0 && g_env.sticks[NEXT_STICK(p->id)] == 0)
		{
			g_env.sticks[p->id] = 1;
			g_env.sticks[NEXT_STICK(p->id)] = 1;
			p->update_timer = EAT_T * ONE_SEC;
			p->state = STATE_EAT;
		}
		pthread_mutex_unlock(&g_lock);
	}
	p->update_timer += 10;
}
