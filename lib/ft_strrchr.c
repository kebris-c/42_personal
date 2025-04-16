/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:04:38 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/13 16:13:18 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*s;
	const char	*val;

	val = NULL;
	s = str;
	while (*s)
	{
		if (c == *s)
			val = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)val);
}
