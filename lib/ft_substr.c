/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:18:18 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/16 19:53:15 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, size_t start, size_t len)
{
	char	*arr;
	size_t	i;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	arr = (char *)malloc((sizeof(char) * len) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len && str[start])
	{
		arr[i] = str[start];
		i++;
		start++;
	}
	arr[i] = '\0';
	return (arr);
}
