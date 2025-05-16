/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:51:23 by kebris-c          #+#    #+#             */
/*   Updated: 2025/05/12 19:11:31 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//	Defines
# define HEX "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"
# define DEC "0123456789"

//	Headers
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

//	Typedefs
typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_printf
{
	va_list			args;
	int				count;
}	t_printf;

//	Prototypes
int		ft_printf(const char *format, ...);
int		ft_print_str(t_printf *printf);
int		ft_print_base(unsigned long long ptr, t_printf *printf, char *base);
int		ft_print_digits(t_printf *printf);
int		ft_print_unsigned(t_printf *printf);
int		ft_print_ptr(t_printf *printf);
int		ft_print_hex_prefix(t_printf *printf, int is_ptr);
size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *str, int std);

#endif
