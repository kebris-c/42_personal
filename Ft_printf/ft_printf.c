#include "printf.h"

static t_bool	ft_parse_flags(char const *format, t_printf *printf)
{
	char	c;

	if (*format == 'c')
	{
		c = GET_ARG(char);
		write(1, &c, 1);
		printf->count++;
	}
	else if (*format == 's')
		ft_print_str(printf);
	else if (*format == 'p' || *format == 'x')
		ft_print_base(GET_ARG(unsigned long long), printf, HEX);
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		ft_print_digits(printf);
	else if (*format == 'X')
		ft_print_base(GET_ARG(unsigned long long), printf, HEXUP);
	else if (*format == '%')
	{
		write(1, "%", 1);
		printf->count++;
	}
	else
		return (FALSE);
	return (TRUE);
}

int	ft_printf(char const *format, ...)
{
	t_printf	printf;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	printf.args = args;
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			if (ft_parse_flags(format + 1, &printf))
			{
				format += 2;
				continue ;
			}
		}
		write(1, *format, 1);
		printf.count++;
		format++;
	}
	va_end(args);
	return (printf.count);
}