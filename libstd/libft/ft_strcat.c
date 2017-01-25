/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:17:37 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/15 19:07:52 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	char *str;

	str = s1;
	while (*str)
		str++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (s1);
}