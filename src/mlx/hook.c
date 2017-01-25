/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static int	hook_count(t_env *en)
{
	int		x;
	int		y;
	int		count;

	x = -1;
	count = 0;
	while (y = -1, ++x <= MAX_X)
	{
		while (++y <= MAX_Y)
		{
			if (en->m[MC(x, y)])
				count++;
		}
	}
	ft_putnbr(count);
	ft_putendl(" players presents.");
	return (0);
}

static int	hook_color(t_env *en)
{
	t_dlst_link *lk;
	t_team		*t;

	if (en->teams->size == 0)
		return (0);
	lk = en->teams->link;
	while (t = NULL, lk)
	{
		if (!(t = (t_team*)lk->content))
		{
			lk = lk->next;
			continue ;
		}
		sprite_reset(en, t->sprite, "rsc/inf1.xpm");
		sprite_reset(en, t->sprite + 1, "rsc/inf2.xpm");
		sprite_reset(en, t->sprite + 2, "rsc/inf3.xpm");
		t->color = team_gen_color(t->teamid, t);
		team_apply_color(en, t->sprite, t->color);
		team_apply_color(en, t->sprite + 1, t->color);
		team_apply_color(en, t->sprite + 2, t->color);
		lk = lk->next;
	}
	ft_putendl("Color changed!");
	return (0);
}

int			hook_key_release(int keycode, t_env *en)
{
	(void)en;
	if (keycode == KEY_QUIT)
		hook_close(NULL);
	if (keycode == KEY_COLOR)
		hook_color(en);
	if (keycode == KEY_COUNT)
		hook_count(en);
	return (0);
}

int			hook_loop(t_env *en)
{
	update_diff(en);
	srand(time(NULL));
	if (update_timer(en, &en->update_timer, 1000 + rand() % 1000))
		env_update_map(en);
	if (update_timer(en, &en->display_timer, 300))
		display(en);
	if (update_timer(en, &en->theme_timer, SOUND_THEME_LEN_MS))
		audio_play(SOUND_THEME);
	mlx_do_sync(en->mlx);
	return (0);
}

int			hook_close(void *null)
{
	int		semid;
	t_env	*en;

	en = NULL;
	en = get_env(NULL);
	(void)null;
	audio_clear();
	ft_putstr("\nProgram interupted. Quitting...\n");
	if ((semid = semget(en->key, 1, SHM_FACCESS)) == -1)
		exit(0);
	if (semctl(semid, 0, GETVAL, 1) == 1 && en->locked)
		semctl(semid, 0, SETVAL, 0);
	exit(0);
	return (0);
}
