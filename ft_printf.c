/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:55:44 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/19 16:38:56 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Conjunto de condicionais que printam no terminal cada formato de dado
// Recebe um especificador de formato e uma lista de argumentos variáveis
static int	print_type(char c, va_list args)
{
	int	counter; // Contador de caracteres printados, que vai ser retornado pela função

	counter = 0;
	if (c == 'c') // Se o especificador for c, se trata de um char
		// "ft_putchar" escreve um char no terminal, e retorna 1 para o char escrito
		return (ft_putchar(va_arg(args, int)));
	if (c == 's') // Se o especificador for s, se trata de uma string
		// "ft_putstr" escreve uma string no terminal, e retorna a len da string escrita
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p') // Se o especificador for p, se trata de um ponteiro
		// "ft_putptr" escreve um ponteiro no terminal, e retorna o número de caracteres escritos
		// Ponteiros são escritos em números hexadecimais com um "0x" na frente
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i') // Se o especificador for d ou i, se trata de um int
		// "ft_putnbr" escreve um número (transformado em string) no terminal, e retorna a quantidade de caracteres escritos
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u') // Se o especificador for u, se trata de um número unsigned long
		// "ft_putunint" escreve um unsigned long (transformado em string) no terminal, e retorna a quantidade de caracteres escritos
		return (ft_putunint(va_arg(args, unsigned int)));
	if (c == 'x') // Se o especificador for x, o output vai ser um número hexadecimal em letras minúsculas
		// "ft_puthexa" escreve um hexadecimal (transformado em string) no terminal, e retorna a quantidade de caracteres escritos
		// 0 significa que o output é minúsculo
		return (ft_puthexa(va_arg(args, unsigned int), 0));
	if (c == 'X') // Se o especificador for X, o output vai ser um número hexadecimal em letras maiúsculas
		// "ft_puthexa" escreve um hexadecimal (transformado em string) no terminal, e retorna a quantidade de caracteres escritos
		// 1 significa que o output é maiúsculo
		return (ft_puthexa(va_arg(args, unsigned int), 1));
	if (c == '%') // Se o especificador for %
	{
		write(1, "%", 1); // Escreve um '%'
		return (1); // Retorna 1 para o único caracter escrito
	}
	else
		return (counter); // Retorna a contagem de caracteres escritos
}

// Printf é uma função variádica, e as reticências na prototipagem indicam os argumentos variáveis
// Funções variádicas precisam ter ao menos um parâmetro fixo, nesse caso, o format
// Format é a string que passamos na printf, possivelmente com texto e com os especificadores de formato
// Retorna um número int, que é o total dos caracteres printados no terminal
int	ft_printf(const char *format, ...)
{
	unsigned int	i; // Índice para iterar sobre a string format
	char			*input; // Variável que guarda o format typecasted para char *
	// va_list é um estrutura vinda da biblioteca stdarg
	va_list			args; // Ela guarda a lista de argumentos variáveis passados na chamada da função
	int				counter; // Contador de caracteres printados

	i = 0;
	counter = 0;
	// Método vindo da biblioteca stdarg
	va_start(args, format); // Inicia a nossa va_list "args", para ela poder ser usada por outras funções
	input = (char *)(format);
	while (input[i] != '\0') // Percorre o input do usuário
	{
		if (input[i] == '%') // Se encontrar um caracter '%'
		// Significa que o caracter seguinte vai ser um especificador de formato
		{
			// "print_type" recebe input[i + 1], para pegar esse especificador de formato
			// "print_type" usa funções ft_put que printam formatos específicos
			// Todas as funções ft_put retornam um int de contagem de caracteres printados
			// Por isso o retorno de "print_type" é somado ao counter
			// "print_type" também recebe args, ou seja, a lista inteira de argumentos varíaveis
			counter += print_type(input[i + 1], args);
			i++; // Avança para passar do '%'
		}
		else // Se não for o caracter '%' ou um especificador de formato
		{
			write(1, &input[i], 1); // Simplesmente escreve o caracter no terminal
			counter++; // E incrementa o contador
		}
		i++; // Avança na string format
	}
	va_end(args); // Libera a lista de argumentos
	return (counter); // Retorna o contador de caracteres printados
}
