/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include <stdio.h>
# include "/Library/Frameworks/SDL.framework/Headers/SDL.h"

# include "libdlst.h"

/*
** === MACROS =============================================================== **
** --- RESOURCES PATHS ------------------------------------------------------ **
*/

# define IMG_ALPHA		"rsc/pic_alpha.bmp"
# define IMG_BG			"rsc/pic_back.bmp"
# define IMG_STATE		"rsc/pic_balloon.bmp"
# define IMG_BOWL		"rsc/pic_bowl.bmp"
# define IMG_CHAIR		"rsc/pic_chair.bmp"
# define IMG_END		"rsc/pic_end.bmp"
# define IMG_DIED		"rsc/pic_end1.bmp"
# define IMG_SURVIVED	"rsc/pic_end2.bmp"
# define IMG_NUM		"rsc/pic_num.bmp"
# define IMG_SPRITE		"rsc/pic_sprite.bmp"
# define IMG_STICK		"rsc/pic_stick.bmp"

/*
** --- KEYS ----------------------------------------------------------------- **
*/

# define CROSS_CLICK	(g_env.sdl.event.type == SDL_QUIT)
# define KEYDOWN		(g_env.sdl.event.type == SDL_KEYUP)
# define KEY_ESC		(g_env.sdl.event.key.keysym.sym == SDLK_ESCAPE)
# define KEY_SPACE		(g_env.sdl.event.key.keysym.sym == SDLK_SPACE)

/*
** --- COLORS --------------------------------------------------------------- **
*/

# define SDL_WHITE		0xffffffff
# define SDL_GRAY		0xffdedede

/*
** --- DIMENSIONS ----------------------------------------------------------- **
*/

# define WIN_W			544
# define WIN_H			416

/*
** --- SPRITESHEET ---------------------------------------------------------- **
*/

# define SPRITE_W		32
# define SPRITE_H		32
# define SLEEP_Y		7 * SPRITE_W
# define SLEEP_X		3 * SPRITE_H
# define EAT_Y			4 * SPRITE_W
# define EAT_X			3 * SPRITE_H
# define THINK_Y		6 * SPRITE_W
# define THINK_X		0 * SPRITE_H
# define WAIT_Y			4 * SPRITE_W
# define WAIT_X			0 * SPRITE_H
#define PHILO_OFFX	164
#define PHILO_OFFY	132
#define	FRAMEDIV	20

/*
** === STRCTURES ============================================================ **
** --- e_bmp ---------------------------------------------------------------- **
**	enum list of all images ids												  **
** -------------------------------------------------------------------------- **
*/

enum			e_bmps
{
	BMP_MIN = -1,
	BMP_ALPHA,
	BMP_BG,
	BMP_STATE,
	BMP_BOWL,
	BMP_CHAIR,
	BMP_END,
	BMP_DIED,
	BMP_SURVIVED,
	BMP_NUM,
	BMP_SPRITE,
	BMP_STICK,
	BMP_MAX
};


/*
** --- t_img ---------------------------------------------------------------- **
**	int			| id		| image id										  **
**	SDL_Surface	| *sur		| image core variable							  **
**	Uint32		| trsp		| color of transparency.						  **
**	SDL_Rect	| *zone		| size of printed zone							  **
** -------------------------------------------------------------------------- **
*/

typedef struct	s_img	// example value
{
	int			id;		// BMP_ALPHA
	SDL_Surface	*sur;	// SDL_LoadBMP(IMG_ALPHA);
	Uint32		trsp;	// 0xffdedede
	SDL_Rect	*zone;	// zone.x/y = 0, zone.w/h = 32
	char		*path;
}				t_img;

/*
** --- t_img ---------------------------------------------------------------- **
**	int			| frame		| current frame									  **
**	SDL_Surface	| *screen	| screen variable								  **
**	SDL_Event	| event		| event variable								  **
**	t_list		| *imgs		| pointer to a list of all images				  **
** -------------------------------------------------------------------------- **
*/

typedef struct	s_sdl
{
	int			frame;
	SDL_Surface	*screen;
	SDL_Event	event;
	t_dlst		*imglst;
	t_img		**imgs;
}				t_sdl;

/*
** === FUNCTIONS ============================================================ **
** --- core.c --------------------------------------------------------------- **
**	sdl_init				| initializes the sdl requirements				  **
**	sdl_update				| updates the screen							  **
** -------------------------------------------------------------------------- **
*/

int				sdl_key_mgr(SDLKey key);
void			sdl_init(t_sdl *sdl);
void			sdl_update(t_sdl *sdl);
void			sdl_end(t_sdl *sdl);

/*
** --- img.c ---------------------------------------------------------------- **
**	img_defrect				| creates a SDL_Rect* variable (uses malloc)	  **
**	img_put					| puts an image on screen						  **
**	img_putnbr				| puts an number on screen						  **
**	img_load				| initialize one image							  **
**	img_list				| initialize the images list					  **
** -------------------------------------------------------------------------- **
*/

SDL_Rect		*img_defrect(int h, int w, int x, int y);
void			img_put(t_sdl *sdl, int id, int x, int y);
void			img_putnbr(t_sdl *sdl, int n, int x, int y);
void			img_load(t_sdl *sdl, int id, char *path, Uint32 trsp);
void			img_list(t_sdl *sdl);

/*
** --- philo.c -------------------------------------------------------------- **
**	philo_display			| core function for displaying philosophers		  **
** -------------------------------------------------------------------------- **
*/

void			philo_display(t_sdl *sdl);



#endif
