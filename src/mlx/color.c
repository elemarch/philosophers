/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

static t_rgba	*color_make(void)
{
	t_rgba	*c;

	return ((c = (t_rgba*)malloc(sizeof(t_rgba))) ? c : NULL);
}

t_rgba	*color_mkrgb(t_col r, t_col g, t_col b)
{
	t_rgba	*c;

	if (!(c = color_make()))
		return (NULL);
	c->c[0] = b;
	c->c[1] = g;
	c->c[2] = r;
	c->a[3] = 0;
	return (c);
}

t_rgba	*color_mkrgba(t_col r, t_col g, t_col b, char a)
{
	t_rgba	*c;

	if (!(c = color_make()))
		return (NULL);
	c->c[0] = b;
	c->c[1] = g;
	c->c[2] = r;
	c->a[3] = a;
	return (c);
}

t_rgba	*color_mkhex(int hex)
{
	t_rgba	*c;

	if (!(c = color_make()))
		return (NULL);
	c->col = hex;
	c->a[3] = 0;
	return (c);
}
