/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:12:39 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/19 16:45:02 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_number(int n)
{
	if (n > 9)
		write_number(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648) // Tratamento para o caso de int min
		return (ft_putstr("-2147483648")); // Escreve ele como string no terminal
	if (n < 0) // Se o número for negativo
	{
		write(1, "-", 1); // Escreve o sinal negativo
		counter++; // Incrementa o contador
		n *= (-1); // Transforma o número em positivo
	}
	write_number(n); // Função recursiva que transforma o int em string
	// O loop abaixo serve para contar a quantidade de dígitos do número
	// Para termos um número de caracteres escritos para retornar
	while (n > 9)
	{
		n = n / 10; // Divide por 10 enquanto possível para pegar cada dígito
		counter++;
	}
	// Quando sai do loop, o número é apenas uma unidade
	counter++; // Que é somada ao contador
	return (counter);
}
