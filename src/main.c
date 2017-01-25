/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/08/09 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** BONUS
** 1) Animated sprites (SDL)
** 2) Keys to change the speed (use of gettimeofday())
** 3) Sounds (use of system())
** 4) Variable philosopher count
*/

#define SDL_PHILO

t_env			g_env;
pthread_mutex_t	g_lock = PTHREAD_MUTEX_INITIALIZER;

#ifdef SDL_PHILO

int	sdl_keyhook(void)
{
	SDL_PollEvent(&(g_env.sdl.event));

	if (CROSS_CLICK || (KEYDOWN && KEY_ESC))
		return (0);
	if (KEYDOWN)
		sdl_key_mgr(g_env.sdl.event.key.keysym.sym);
	if (!g_env.is_running)
		return (0);
	return (1);
}

#endif

int		main(int ac, char **av)
{
	env_init(philo_count(ac, av));
	while (1)
	{

		#ifdef SDL_PHILO
		if (!sdl_keyhook())
			break ;
		#endif
		#ifdef MLX_PHILO
		#endif
	}
	#ifdef SDL_PHILO
	sdl_end(&g_env.sdl);
	#endif
	env_stop();
	return (0);
}


