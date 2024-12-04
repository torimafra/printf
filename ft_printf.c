/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:55:44 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/19 15:03:28 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_type(char c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunint(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), 1));
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
		return (counter);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	char			*input;
	va_list			args;
	int				counter;

	i = 0;
	counter = 0;
	va_start(args, format);
	input = (char *)(format);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			counter += print_type(input[i + 1], args);
			i++;
		}
		else
		{
			write(1, &input[i], 1);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}
