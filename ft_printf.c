/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:20:27 by amarouf           #+#    #+#             */
/*   Updated: 2023/12/12 12:23:37 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	if (write(1, "", 0) == -1)
		return (-1);
	if (str[i] == '%' && str[i + 1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += ft_wichone(str[i + 1], args);
			i += 2;
		}
		else
			count += write(1, &str[i ++], 1);
	}
	va_end(args);
	return (count);
}
// int main ()
// {
// 	char p[] = "hello";

// 	printf("%d: \n", printf("%p",p));
// 	printf("%d: \n", ft_printf("%p",p));
// }
