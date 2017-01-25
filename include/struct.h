/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

# include "gui.h"

# define PHILOSOPHER_COUNT	7
# define NEXT_STICK(x) ((x + 1 == PHILOSOPHER_COUNT) ? 0 : x + 1)

enum			e_state
{
	STATE_EAT = 1,
	STATE_SLEEP,
	STATE_THINK,
	STATE_WAIT,
	STATE_MAX
};


enum			e_imgs
{
	IMGS_MIN = -1,
	IMGS_ALPHA,
	IMGS_BG,
	IMGS_STATE,
	IMGS_BOWL,
	IMGS_CHAIR,
	IMGS_END,
	IMGS_NUM,
	IMGS_SPRITE,
	IMGS_STICK,
	IMGS_MAX
};

/*
** t_times - time datas
** ******************* **
** old	 - previous timestamp
** curr	 - current timestamp
** diff	 - time spent between previous and current in ms
** ******************* **
*/
typedef struct		s_times
{
	double		old;
	double		curr;
	double		diff;
}					t_times;

typedef struct		s_philosopher
{
	pthread_t		thread;
	int				id;
	int				hp;
	enum e_state	state;
	int				update_timer;
	t_times			time;
}					t_philosopher;

typedef t_philosopher	t_p;

/*
** t_env - environment
** ******************************************************************* **
** p			-	phisolophers structs
** sticks		-	chopsticks, 0 = used, 1 = available
** time			-	times data for update timers
** update_timer	-	main timer that update the philosophers actions & hp
** over_timer	-	timer to end simulation
** update_len	-	time between two updates
** ******************************************************************* **
*/
typedef struct		s_env
{
	t_philosopher	p[PHILOSOPHER_COUNT];
	int				sticks[PHILOSOPHER_COUNT];
	t_times			time;
	int				update_timer;
	int				over_timer;
	int				update_len;
	int				refresh_timer;
	int				philosopher_count;
	void			(*updates[STATE_MAX])(t_philosopher *p);
	int				is_running;
	t_sdl			sdl;
	int				pause;
}					t_env;

#endif
