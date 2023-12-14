/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertprints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:48:50 by amarouf           #+#    #+#             */
/*   Updated: 2023/12/12 20:41:23 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	converthexa(unsigned long a, int isupper)
{
	char			*p;
	char			address[20];
	int				i;
	int				count;

	if (a == 0)
		return (write(1, "0", 1));
	p = "0123456789abcdef";
	i = 0;
	count = 0;
	if (isupper == 1)
		p = "0123456789ABCDEF";
	while (a > 0)
	{
		address[i ++] = p[a % 16];
		a = a / 16;
		count ++;
	}
	i --;
	while (i >= 0)
		write (1, &address[i --], 1);
	return (count);
}

int	ft_putunbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putchar(nb + 48);
	return (count);
}

int	ft_wichone(char p, va_list args)
{
	int	count;

	count = 0;
	if (p == 'c')
		count += ft_putchar(va_arg(args, int));
	if (p == '%')
		count += write(1, "%", 1);
	if (p == 's')
		count += ft_putstr(va_arg(args, char *));
	if (p == 'd' || p == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (p == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	if (p == 'p')
	{
		count += write (1, "0x", 2);
		count += converthexa(va_arg(args, unsigned long), 0);
	}
	if (p == 'x')
		count += converthexa(va_arg(args, unsigned int), 0);
	if (p == 'X')
		count += converthexa(va_arg(args, unsigned int), 1);
	return (count);
}
