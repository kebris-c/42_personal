#include "printf.h"

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
	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(std, &str[i], 1);
		i++;
	}
}
/*
char	*ft_strdup_bzero(void *src, size_t n)
{
	size_t			i;
	size_t			len;
	char			*dup;
	char			*tmp;
	unsigned char	*p;

	if (n == 0)
	{
		tmp = (char *)src;
		len = ft_strlen(tmp);
		dup = malloc(len + 1);
		if (!dup)
			return (NULL);
		i = 0;
		while (i < len)
		{
			dup[i] = tmp[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
	p = (unsigned char *)src;
	while (n--)
		*p++ = 0;
}

char	*ft_substr(const char *str, unsigned int start, unsigned int len)
{
	char	*sub;
	size_t	i;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen((char *)str);
	if (start >= str_len)
		return (ft_strdup_bzero((void *)"", 0));
	if (len > str_len - start)
		len = str_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && str[start + i])
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr(char const *str, char c)
{
	if (!str)
		return (NULL);
	if (!c)
		return (str);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
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

t_bool	ft_itoa_base(unsigned long long p, char *base, t_printf *print)
{
	char	*nb;
	size_t	itoa_len;
	size_t	base_len;

	if (printf->p)
		ft_putstr_fd("0x", 1);
	itoa_len = ft_itoa_len(p, base);
	printf->count += itoa_len;
	nb = malloc(sizeof(char) * (itoa_len + 1));
	if (!nb)
		return (FALSE);
	base_len = ft_strlen(base);
	nb[itoa_len] = '\0';
	while (p)
	{
		nb[--itoa_len] = base[p % base_len];
		p /= base_len;
	}
	ft_putstr_fd(nb, 1);
	free(nb);
	return (TRUE);
}
*/