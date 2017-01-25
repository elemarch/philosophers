/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 16:14:10 by esaminad          #+#    #+#             */
/*   Updated: 2015/02/04 16:16:51 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnum(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if ((*str == '-' || *str == '+' || *str == ' ') ||
			(*str >= '0' && *str <= '9'))
			str++;
		else
			return (0);
	}
	return (1);
}