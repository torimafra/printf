/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:02:38 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/19 17:05:18 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Números hexadecimais são número de base 16
// Do mesmo jeito que números decimais, de base 10, tem unidades baseadas em potências de 10 (0, 10 , 100, 1000, etc)
// Os hexadecimais tem unidades baseadas em potências de 16 (0, 1, 256, 4096, etc)
// Os números decimais usam os dígitos de 0 a 9 (10 no total) para representar valores
// Os números hexadecimais usam os caracteres de 0 a 9 + 'A' a 'F' (16 no total) para representar valores

static void	write_lower_hexa(unsigned long n)
{
	if ((n / 16) > 0)
		write_lower_hexa(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

static void	write_upper_hexa(unsigned long n)
{
	if ((n / 16) > 0)
		write_upper_hexa(n / 16);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
}

// "ft_puthexa" recebe um unsigned long e um int que indica se o output será minúsculo ou maiúsculo
int	ft_puthexa(unsigned long n, int type)
{
	int	counter;

	counter = 0;
	if (type == 0) // Se for 0, é minúsculo
		write_lower_hexa(n);
	if (type == 1) // Se for 1, é maiúsculo
		write_upper_hexa(n);
	// O bloco de while abaixo vai contar o número de dígitos do número hexadecimal
	// Dividindo ele consecutivamente por 16 (como faríamos com 10 em um número decimal)
	while ((n / 16) > 0)
	{
		n = n / 16;
		counter++;
	}
	// Ao sair do loop, o número restante será igual ou menos a 16, ou seja, uma unidade hexadecimal
	counter++; // Adiciona ela ao contador
	return (counter);
}
