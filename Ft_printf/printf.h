#ifndef PRINTF_H
# define PRINTF_H

//	Defines
# define GET_ARG(type) va_arg(printf->args, type)
# define HEX "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"
# define DEC "0123456789"

//	Headers
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

//	Typedefs
typedef enum	e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct	s_printf
{
	va_list			args;
	int				count;
}	t_printf;

//	Prototypes
int		ft_printf(const char *, ...);
int		ft_print_str(t_printf *printf);
int		ft_print_base(unsigned long long ptr, t_printf *printf, char *base);
int		ft_print_digits(t_printf *printf);
size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *str, int std);

#endif