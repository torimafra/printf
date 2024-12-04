/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:46:28 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/19 14:53:13 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_number(unsigned int n)
{
	if (n > 9)
		write_number(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	ft_putunint(unsigned int n)
{
	int	counter;

	counter = 0;
	write_number(n);
	while (n > 9)
	{
		n = n / 10;
		counter++;
	}
	counter++;
	return (counter);
}
