/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/01 19:53:39 by elemarch          #+#    #+#             */
/*   Updated: 2015/09/01 19:53:41 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

SDL_Rect	*img_defrect(int h, int w, int x, int y)
{
	SDL_Rect	*rect;

	rect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	if (h > -1)
		rect->h = h;
	if (w > -1)
	rect->w = w;
	if (x > -1)
	rect->x = x;
	if (y > -1)
	rect->y = y;
	return (rect);
}

void		img_put(t_sdl *sdl, int id, int x, int y)
{
	SDL_Rect	*dest;

	dest = img_defrect(0, 0, x, y);
	SDL_BlitSurface(sdl->imgs[id]->sur, sdl->imgs[id]->zone, sdl->screen, dest);
	FREE(dest);
}

void		img_putnbr(t_sdl *sdl, int n, int x, int y)
{
	char	*number;
	int		i;
	int		num_width;

	num_width = sdl->imgs[BMP_NUM]->zone->w;
	i = 0;
	number = ft_itoa(n);
	while (number[i])
	{
		sdl->imgs[BMP_NUM]->zone->x = (number[i] - '0') * num_width;
		img_put(sdl, BMP_NUM, x, y);
		x += 13;
		i++;
	}
}

void		img_load(t_sdl *sdl, int id, char *path, Uint32 trsp)
{
	t_img	*new_img;

	new_img = (t_img*)malloc(sizeof(t_img));
	new_img->id = id;
	new_img->zone = NULL;
	new_img->path = ft_strdup(path);
	new_img->sur = SDL_LoadBMP(path);
	new_img->sur->format->Amask = 0xFF000000;
	new_img->sur->format->Ashift = 24;
	SDL_SetColorKey(new_img->sur, SDL_SRCCOLORKEY, trsp);
	dlst_push_back_c(sdl->imglst, new_img, sizeof(new_img));
}

void		img_list(t_sdl *sdl)
{
	sdl->imglst = dlst_new();
	img_load(sdl, BMP_ALPHA, IMG_ALPHA, SDL_WHITE);
	img_load(sdl, BMP_BG, IMG_BG, SDL_WHITE);
	img_load(sdl, BMP_STATE, IMG_STATE, SDL_WHITE);
	img_load(sdl, BMP_BOWL, IMG_BOWL, SDL_GRAY);
	img_load(sdl, BMP_CHAIR, IMG_CHAIR, SDL_GRAY);
	img_load(sdl, BMP_END, IMG_END, SDL_GRAY);
	img_load(sdl, BMP_DIED, IMG_DIED, SDL_WHITE);
	img_load(sdl, BMP_SURVIVED, IMG_SURVIVED, SDL_WHITE);
	img_load(sdl, BMP_NUM, IMG_NUM, SDL_WHITE);
	img_load(sdl, BMP_SPRITE, IMG_SPRITE, SDL_WHITE);
	img_load(sdl, BMP_STICK, IMG_STICK, SDL_GRAY);
	sdl->imgs = (t_img **)dlst_to_array(sdl->imglst);
	sdl->imgs[BMP_STATE]->zone = img_defrect(32, 32, 32 * 7, 0);
	sdl->imgs[BMP_NUM]->zone = img_defrect(26, 21, 0, 0);
	sdl->imgs[BMP_SPRITE]->zone = img_defrect(32, 32, 0, 0);
}
