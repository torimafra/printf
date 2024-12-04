/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:02:38 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/21 13:43:47 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_hexa(unsigned long n, char *s)
{
	if ((n / 16) > 0)
		write_hexa(n / 16, s);
	write(1, &s[n % 16], 1);
}

int	ft_puthexa(unsigned long n, int type)
{
	char	*upper;
	char	*lower;
	int		counter;

	counter = 0;
	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	if (type == 0)
		write_hexa(n, lower);
	if (type == 1)
		write_hexa(n, upper);
	while ((n / 16) > 0)
	{
		n = n / 16;
		counter++;
	}
	counter++;
	return (counter);
}
