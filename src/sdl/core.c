/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/01 19:53:39 by elemarch          #+#    #+#             */
/*   Updated: 2015/09/01 19:53:41 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
# define PHILO_SDL

int		sdl_key_mgr(SDLKey key)
{
	if (g_env.sdl.event.key.keysym.sym == SDLK_RIGHT)
		g_env.update_len = ONE_SEC / 2;
	if (key == SDLK_LEFT)
		g_env.update_len = ONE_SEC * 2;
	if (key == SDLK_DOWN)
		g_env.update_len = ONE_SEC;
	if (key == SDLK_SPACE && !g_env.pause)
		g_env.pause = 1;
	else if (key == SDLK_SPACE && g_env.pause)
		g_env.pause = 0;
	if (key == SDLK_ESCAPE)
		return (0);
	return (1);
}

void	sdl_init(t_sdl *sdl)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	g_env.sdl.frame = 0;
	g_env.sdl.screen = SDL_SetVideoMode(WIN_W, WIN_H, 32, SDL_HWSURFACE);
	img_list(sdl);
	sdl->imglst = dlst_new();
}

void	sdl_update(t_sdl *sdl)
{
	img_put(sdl, BMP_BG, 0, 0);
	philo_display(sdl);
	img_putnbr(sdl, g_env.over_timer / 1000, 450, 270);
	if (g_env.update_len == 500)
		img_put(sdl, BMP_STICK, 360, 165);
	if (g_env.update_len == 1000)
		img_put(sdl, BMP_STICK, 360, 134);
	if (g_env.update_len == 2000)
		img_put(sdl, BMP_STICK, 360, 100);
	SDL_Flip(sdl->screen);
}

void	sdl_end(t_sdl *sdl)
{
	int		i;

	i = 0;
	img_put(sdl, BMP_END, 0, 0);
	while (i < g_env.philosopher_count)
	{
		if (g_env.p[i].hp == 0)
		{
			img_put(sdl, BMP_DIED, 90, 200);
			img_putnbr(sdl, i, 318, 208);
			break ;
		}
		i++;
	}
	if (i == g_env.philosopher_count)
		img_put(sdl, BMP_SURVIVED, 90, 200);
	SDL_Flip(sdl->screen);
	SDL_WaitEvent(&(g_env.sdl.event));
		if (g_env.sdl.event.type == SDL_QUIT)
			SDL_Quit();
}
