/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:27:36 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/19 14:51:17 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	long	adress;
	int		counter;

	counter = 2;
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	adress = (unsigned long)(ptr);
	write(1, "0x", 2);
	counter += ft_puthexa(adress, 0);
	return (counter);
}
