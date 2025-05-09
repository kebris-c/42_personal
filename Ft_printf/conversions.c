#include "printf.h"

int	ft_print_str(t_printf *printf)
{
	char	*str;

	str = GET_ARG(char *);
	if (!str)
		return (printf->count);
	printf->count += ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (printf->count);
}

int	ft_print_base(unsigned long long ptr, t_printf *printf, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (ptr >= base_len)
		printf->count += ft_print_base(ptr / base_len, printf, base);
	printf->count += write(1, &base[ptr % base_len], 1);
	return (printf->count);
}

int	ft_print_digits(t_printf *printf)
{
	int	nb;

	nb = GET_ARG(int);
	if (nb < 0)
	{
		write(1, '-', 1);
		printf->count++;
		nb = -nb;
	}
	ft_print_base((unsigned long long)nb, printf, DEC);
	return (printf->count);
}