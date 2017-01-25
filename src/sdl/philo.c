/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/01 19:53:39 by elemarch          #+#    #+#             */
/*   Updated: 2015/09/01 19:53:41 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#define ZONE		(sdl->imgs[BMP_SPRITE]->zone)

int		philo_frame(t_sdl *sdl)
{
	if (sdl->frame / FRAMEDIV== 3)
		sdl->frame = 0;
	else
		sdl->frame++;
	if (sdl->frame / FRAMEDIV == 3)
		return (SPRITE_W);
	else
		return (SPRITE_W * (sdl->frame / FRAMEDIV));
}

void	philo_bubble(t_sdl *sdl, int id, int x, int y)
{
	if (g_env.p[id].state == STATE_EAT)
		sdl->imgs[BMP_STATE]->zone = img_defrect(32, 32, 32 * 7, 32 * 3);
	if (g_env.p[id].state == STATE_SLEEP)
		sdl->imgs[BMP_STATE]->zone = img_defrect(32, 32, 32 * 7, 32 * 9);
	if (g_env.p[id].state == STATE_THINK)
		sdl->imgs[BMP_STATE]->zone = img_defrect(32, 32, 32 * 7, 32 * 1);
	if (g_env.p[id].state == STATE_WAIT)
		sdl->imgs[BMP_STATE]->zone = img_defrect(32, 32, 32 * 7, 32 * 7);
	img_put(sdl, BMP_STATE, x, y - 32);
}

void	philo_life(t_sdl *sdl, int id, int x, int y)
{
	SDL_Rect	*rect;
	int			hp;

	hp = g_env.p[id].hp * 20 / MAX_LIFE;
	printf("hp: %d\n", hp);
	rect = img_defrect(7, 22, x + 5, y - 26);
	SDL_FillRect(sdl->screen, rect, SDL_WHITE);
	FREE(rect);
	rect = img_defrect(5, hp, x + 6, y - 25);
	SDL_FillRect(sdl->screen, rect, SDL_MapRGB(sdl->screen->format, 255, 0, 0));
	FREE(rect);
}

void	philo_sprite(t_sdl *sdl, int id, int x, int y)
{
	int		f;

	f = philo_frame(sdl);
	if (g_env.p[id].state == STATE_EAT)
		ZONE = img_defrect(SPRITE_H, SPRITE_W, EAT_X + f, EAT_Y);
	if (g_env.p[id].state == STATE_SLEEP)
		ZONE = img_defrect(SPRITE_H, SPRITE_W, SLEEP_X + f, SLEEP_Y);
	if (g_env.p[id].state == STATE_THINK)
		ZONE = img_defrect(SPRITE_H, SPRITE_W, THINK_X + f, THINK_Y);
	if (g_env.p[id].state == STATE_WAIT)
		ZONE = img_defrect(SPRITE_H, SPRITE_W, WAIT_X + f, WAIT_Y);
	img_put(sdl, BMP_SPRITE, x, y);
	if (g_env.p[id].state == STATE_EAT)
		img_put(sdl, BMP_BOWL, x, y + 20);
	philo_bubble(sdl, id, x, y);
	philo_life(sdl, id, x, y);
}

void	philo_display(t_sdl *sdl)
{
	int		i;
	int		x;
	int		y;

	i = 1;
	x = PHILO_OFFX;
	y = PHILO_OFFY;
	philo_sprite(sdl, 0, x, y);
	while (i <= g_env.philosopher_count / 2 && i != g_env.philosopher_count - i)
	{
		y += 64;
		x = PHILO_OFFX - 32;
		philo_sprite(sdl, i, x, y);
		x += 64;
		philo_sprite(sdl, g_env.philosopher_count - i, x, y);
		i++;
	}
	if (i == g_env.philosopher_count / 2)
		philo_sprite(sdl, g_env.philosopher_count - i, PHILO_OFFX, y + 64);
}
