/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:28:24 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/14 21:44:35 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack)
		return (NULL);
	if (!needle || needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		j = 0;
		while (haystack[i] == needle[j] && (i < len))
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack);
			j++;
			i++;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
