/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:59:18 by kebris-c          #+#    #+#             */
/*   Updated: 2025/05/12 18:52:11 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

static void	aux(void)
{
	int		r1;
	int		r2;

	r1 = printf("orig: %%i: [%i]\n", 1337);
	r2 = ft_printf("mine: %%i: [%i]\n", 1337);
	printf("Retorno printf: %d | ft_printf: %d\n\n", r1, r2);
	r1 = printf("orig: %%%%u: [%u]\n", UINT_MAX);
	r2 = ft_printf("mine: %%%%u: [%u]\n", UINT_MAX);
	printf("Retorno printf: %d | ft_printf: %d\n\n", r1, r2);
	r1 = printf("orig: %%x: [%x]\n", 48879);
	r2 = ft_printf("mine: %%x: [%x]\n", 48879);
	printf("Retorno printf: %d | ft_printf: %d\n\n", r1, r2);
	r1 = printf("orig: %%%%X: [%X]\n", 48879);
	r2 = ft_printf("mine: %%%%X: [%X]\n", 48879);
	printf("Retorno printf: %d | ft_printf: %d\n\n", r1, r2);
	r1 = printf("orig: %%: [%%]\n");
	r2 = ft_printf("mine: %%: [%%]\n");
	printf("Retorno printf: %d | ft_printf: %d\n\n", r1, r2);
}

int	main(void)
{
	int		r1;
	int		r2;
	void	*ptr;

	r1 = printf("orig: %%c: [%c]\n", 'A');
	r2 = ft_printf("mine: %%c: [%c]\n", 'A');
	printf("Retorno printf: %d | ft_printf: %d\n\n", r1, r2);
	r1 = printf("orig: %%s: [%s]\n", "Hola mundo");
	r2 = ft_printf("mine: %%s: [%s]\n", "Hola mundo");
	printf("Retorno printf: %d | ft_printf: %d\n\n", r1, r2);
	r1 = printf("orig: %%s NULL: [%s]\n", (char *) NULL);
	r2 = ft_printf("mine: %%s NULL: [%s]\n", (char *) NULL);
	printf("Retorno printf: %d | ft_printf: %d\n\n", r1, r2);
	ptr = (void *)0x1234ABCD;
	r1 = printf("orig: %%p: [%p]\n", ptr);
	r2 = ft_printf("mine: %%p: [%p]\n", ptr);
	printf("Retorno printf: %d | ft_printf: %d\n\n", r1, r2);
	r1 = printf("orig: %%d: [%d]\n", -42);
	r2 = ft_printf("mine: %%d: [%d]\n", -42);
	printf("Retorno printf: %d | ft_printf: %d\n\n", r1, r2);
	aux();
	return (0);
}
