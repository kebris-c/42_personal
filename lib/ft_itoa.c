/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:00:13 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/16 13:06:01 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	int		len;
	long	n;
	char	*nbr;

	if (nb == 0)
		return (ft_strdup("0"));
	n = (long)nb;
	len = ft_itoa_len(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	if (n < 0)
	{
		n = -n;
		nbr[0] = '-';
	}
	while (n)
	{
		nbr[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (nbr);
}
