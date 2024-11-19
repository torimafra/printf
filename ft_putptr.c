/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:27:36 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/19 17:10:12 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Recebe um ponteiro void
int	ft_putptr(void *ptr)
{
	long	adress;
	int		counter;

	// O contador já inicia em 2 porque sempre que vamos printar um ponteiro, ele precisa começar com "0x"
	// Seguido de um número hexadecimal em letras minúsculas
	counter = 2; // Corresponde ao "0x"
	if (ptr == NULL) // Se o ponteiro for nulo
	{
		ft_putstr("(nil)"); // Escreve a string "(nil)"
		return (5); // Retorna o número de caracteres de "(nil)"
	}
	adress = (unsigned long)(ptr); // Casting do endereço recebido para unsigned long
	write(1, "0x", 2);
	counter += ft_puthexa(adress, 0); // Escreve o unsigned long adress como hexadecimal minúsculo
	return (counter);
}
