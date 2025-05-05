#include "printf.h"

static t_bool	ft_exec_flag_aux(char flag, t_print *print)
{
	if (flag == 'p')
	{
		print->p = GET_ARG(void *);
		print->p = (unsigned long long)print->p;
		ft_putstr_fd("0x", 1);
		return (ft_itoa_base(print->p, HEX, print));
	}
	if (flag == 'd' || flag == 'i')
	{
		print->i = GET_ARG(int);
		print->count += print->i;
		if (print->i < 0)
		{
			write(1, '-', 1);
			print->i *= -1;
		}
		return (ft_itoa_base((unsigned long long)print->i, DEC, print));
	}
	print->x = GET_ARG(unsigned int);
	if (flag == 'x')
		return (ft_itoa_base((unsigned long long)print->x, HEX, print));
	if (flag == 'X')
		return (ft_itoa_base((unsigned long long)print->x, HEXU, print));
}

static t_bool	ft_exec_flag(char flag, t_print *print)
{
	if (flag == '%' || flag == 'c')
	{
		if (flag == '%')
			write(1, '%', 1);
		else
			write(1, GET_ARG(int), 1);
		print->count++;
	}
	else if (flag == 's')
	{
		print->s = GET_ARG(char *);
		print->count += ft_strlen(print->s);
		ft_putstr_fd(print->s, 1);
	}
	else if (flag == 'p' || flag == 'd' || flag == 'i'
		|| flag == 'x' || flag == 'X')
		return (ft_exec_flag_aux(flag, print));
	else
	{
		print->u = GET_ARG(unsigned int);
		print->count += print->u;
		return (ft_itoa_base((unsigned long long)print->u, DEC, print));
	}
	return (TRUE);
}

int	ft_printf(char const *format, ...)
{
	t_print	*print;
	int		i;

	if (!format || !*format)
		return (-1);
	va_start(print->args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (!ft_exec_flag(format[i + 1], print))
				return (-1);
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(print->args);
	return (print->count);
}