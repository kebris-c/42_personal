#include "printf_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *str, int std)
{
	int	i;

	if (std < 0)
		std = 1;
	i = 0;
	while (str[i])
	{
		write(std, &str[i], 1);
		i++;
	}
}

static size_t	ft_itoa_len(unsigned long long p, char *base)
{
	size_t	len;
	size_t	base_len;

	base_len = ft_strlen(base);
	len = 0;
	while (p)
	{
		p /= base_len;
		len++;
	}
	return (len);
}

t_bool	ft_itoa_base(unsigned long long p, char *base, t_print *print)
{
	char	*nb;
	size_t	itoa_len;
	size_t	base_len;

	itoa_len = ft_itoa_len(p, base);
	print->count += itoa_len;
	nb = malloc(sizeof(char) * (itoa_len + 1));
	if (!nb)
		return (FALSE);
	base_len = ft_strlen(base);
	nb[itoa_len + 1] = '\0';
	while (p)
	{
		nb[itoa_len] = base[p % base_len];
		itoa_len--;
		p /= base_len;
	}
	ft_putstr_fd(nb, 1);
	free(nb);
	return (TRUE);
}