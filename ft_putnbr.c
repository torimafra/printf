/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:12:39 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/19 14:50:01 by vimafra-         ###   ########.fr       */
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
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		write(1, "-", 1);
		counter++;
		n *= (-1);
	}
	write_number(n);
	while (n > 9)
	{
		n = n / 10;
		counter++;
	}
	counter++;
	return (counter);
}
