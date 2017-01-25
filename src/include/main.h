/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/08/09 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "struct.h"

# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>

#include "/nfs/zfs-student-5/users/2014/elemarch/.brew/Cellar/sdl/1.2.15/include/SDL/SDL.h"

# define MAX_LIFE 5
# define EAT_T 1
# define SLEEP_T 1
# define THINK_T 1
# define TIMEOUT 60
# define HP_LOSS_TIMER	1
# define ONE_SEC		1000
# define ONE_10SEC		100

# define END_PHRASE "Now, it is time... To DAAAAAAAANCE!!!"

extern pthread_mutex_t	g_lock;
extern t_env			g_env;

/*
** ENV.C
*/
void		env_init(int count);
void		env_stop(void);

/*
** EXIT.C
*/

/*
** MAIN.C
*/

/*
** PHILOSOPHER.C
*/
void		philo_init(t_philosopher *p, int id);
int			philo_update_hp(void);
void		philo_show_health(void);
int			philo_count(int ac, char **av);
void		philo_main_update(t_philosopher *p);

/*
** THREAD.C
*/
void		*thread_main(void *data);
void		thread_eat(t_philosopher *p);
void		thread_sleep(t_philosopher *p);
void		thread_think(t_philosopher *p);
void		thread_wait(t_philosopher *p);

/*
** TIMER.C
*/
void		time_init(t_times *t);
void		update_diff(t_times *t);
int			update_timer(t_times *t, int *timer, int reload);

/*
** ************************************************************************* **
** *************************** ALLOWED FUNCTIONS *************************** **
** ************************************************************************* **
** Basics :
** . malloc
** . free
** . write, read
** . exit
** Time :
** . usleep(useconds_t useconds)
**     - suspend thread execution for an interval measured in microseconds
** . time
**     - Give timestamp (sec since jan 1st 1970)
** Thread
** . pthread_create
**     - Create a thread and get it ready
** . pthread_join
**     - Joining a thread will start the funciton given as param in
**       pthread_create
** . pthread_detach
**     -
** . Mutex
** pthread_mutex_init.
** pthread_mutex_destroy.
** pthread_mutex_trylock.
** pthread_mutex_lock.
** pthread_mutex_unlock.
*/

#endif
