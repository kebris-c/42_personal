#include "printf.h"
#include <stdio.h>
#include <limits.h>

#define GREEN   "\033[0;32m"
#define RED     "\033[0;31m"
#define RESET   "\033[0m"

void compare_returns(int ret_ft, int ret_sys)
{
	if (ret_ft == ret_sys)
		printf(GREEN "return OK ✔️ ft=%d | sys=%d\n\n" RESET, ret_ft, ret_sys);
	else
		printf(RED "return MISMATCH ❌ ft=%d | sys=%d\n\n" RESET, ret_ft, ret_sys);
}

int main(void)
{
	int	ret_ft, ret_sys;
	int	num = -42;
	unsigned int u = 4294967295U;
	void *ptr = &num;
	char c = 'A';
	char *str = "Texto de prueba";

	// %c
	ret_ft = ft_printf("ft: Carácter: [%c]\n", c);
	ret_sys = printf("sys: Carácter: [%c]\n", c);
	compare_returns(ret_ft, ret_sys);

	// %s
	ret_ft = ft_printf("ft: Cadena: [%s]\n", str);
	ret_sys = printf("sys: Cadena: [%s]\n", str);
	compare_returns(ret_ft, ret_sys);

	// %s con NULL
	ret_ft = ft_printf("ft: Cadena NULL: [%s]\n", (char *)NULL);
	ret_sys = printf("sys: Cadena NULL: [%s]\n", (char *)NULL);
	compare_returns(ret_ft, ret_sys);

	// %p
	ret_ft = ft_printf("ft: Puntero: [%p]\n", ptr);
	ret_sys = printf("sys: Puntero: [%p]\n", ptr);
	compare_returns(ret_ft, ret_sys);

	// %d, %i
	ret_ft = ft_printf("ft: Decimal (d): [%d] | Entero (i): [%i]\n", num, num);
	ret_sys = printf("sys: Decimal (d): [%d] | Entero (i): [%i]\n", num, num);
	compare_returns(ret_ft, ret_sys);

	// %d extremos
	ret_ft = ft_printf("ft: INT_MIN: [%d], INT_MAX: [%d]\n", INT_MIN, INT_MAX);
	ret_sys = printf("sys: INT_MIN: [%d], INT_MAX: [%d]\n", INT_MIN, INT_MAX);
	compare_returns(ret_ft, ret_sys);

	// %u
	ret_ft = ft_printf("ft: Unsigned: [%u]\n", u);
	ret_sys = printf("sys: Unsigned: [%u]\n", u);
	compare_returns(ret_ft, ret_sys);

	// %x, %X
	ret_ft = ft_printf("ft: Hexa minúsculas: [%x] | mayúsculas: [%X]\n", 48879, 48879);
	ret_sys = printf("sys: Hexa minúsculas: [%x] | mayúsculas: [%X]\n", 48879, 48879);
	compare_returns(ret_ft, ret_sys);

	// %%
	ret_ft = ft_printf("ft: Porcentaje doble: [%%]\n");
	ret_sys = printf("sys: Porcentaje doble: [%%]\n");
	compare_returns(ret_ft, ret_sys);

	return 0;
}