#ifndef PRINTF_H
# define PRINTF_H

//	Defines
# define GET_ARG(type) va_arg(print->args, type)
# define HEX "0123456789abcdef"
# define HEXU "0123456789ABCDEF"
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

typedef struct	s_print
{
	va_list			args;
	int				count;
	int				i;
	char			*s;
	void			*p;
	unsigned int	u;
	unsigned int	x;
}	t_print;

//	Prototypes
int		ft_printf(const char *, ...);
t_bool	ft_itoa_base(unsigned long long p, char *base, t_print *print);
void	ft_putstr_fd(char *str, int std);
size_t	ft_strlen(char *str);

#endif