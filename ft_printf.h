/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:53:59 by amarouf           #+#    #+#             */
/*   Updated: 2023/12/10 20:40:36 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_putnbr(int n);
int		ft_putstr(char *s);
size_t	ft_strlen(char *s);
int		ft_putchar(char c);
int		converthexa(unsigned long a, int isupper);
int		ft_wichone(char p, va_list args);
int		ft_countnbr(int ncount);
int		ft_countnbr(int ncount);

#endif
