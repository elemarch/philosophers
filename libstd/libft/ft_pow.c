/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 17:18:34 by esaminad          #+#    #+#             */
/*   Updated: 2015/02/04 18:43:37 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int nbr, int pow)
{
	int r;

	if (pow == 0)
		return (1);
	if (nbr == 0)
		return (0);
	if (pow == 1)
		return (nbr);
	r = nbr;
	while (pow-- >= 0)
		r *= nbr;
	return (r);
}