/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additionalfuncs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:55:38 by amarouf           #+#    #+#             */
/*   Updated: 2023/12/10 19:42:07 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	count += write(1, s, ft_strlen(s));
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = ft_countnbr(n);
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	return (count);
}

int	ft_countnbr(int ncount)
{
	int	count;

	if (ncount == 0)
		return (1);
	count = 0;
	while (ncount != 0)
	{
		ncount = ncount / 10;
		count ++;
	}
	return (count);
}
