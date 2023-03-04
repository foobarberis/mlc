/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:19:38 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/06 17:28:20 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlc.h"
#include <stdarg.h>

#define BASE10 "0123456789"
#define BASE16UP "0123456789ABCDEF"
#define BASE16LOW "0123456789abcdef"

int	printf__putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	printf__putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, f_strlen(s)));
}

int	printf__putnbr_base(long n, char *base)
{
	int		i;
	int		l;
	int		r;
	char	num[32];

	i = 0;
	r = 0;
	l = f_strlen(base);
	if (!n)
		return (write(1, &base[0], 1));
	if (n < 0)
	{
		r += printf__putchar_fd('-', 1);
		n = f_abs(n);
	}
	while (n)
	{
		num[i++] = base[n % l];
		n /= l;
	}
	while (--i >= 0)
		r += write(1, &num[i], 1);
	return (r);
}

int	printf__putnbr_fd(int64_t n, int fd)
{
	int		i;
	int		r;
	char	num[32];

	i = 0;
	r = 0;
	if (!n)
		return (write(fd, "0", 1));
	if (n < 0)
		r += printf__putchar_fd('-', fd);
	n = f_abs(n);
	while (n)
	{
		num[i++] = n % 10 + '0';
		n /= 10;
	}
	while (--i >= 0)
		r += write(fd, &num[i], 1);
	return (r);
}

/**
 * @brief Print the output corresponding to each %-construct in the format
 * string.
 * @param c The character following a % in the format string.
 * @param ap The list of variable arguments.
 * @return The number of characters printed.
 */
int	printf__subperc(char c, va_list *ap)
{
	if (c == 'c')
		return (printf__putchar_fd(va_arg(*ap, int), 1));
	if (c == 's')
		return (printf__putstr_fd(va_arg(*ap, char *), 1));
	if (c == 'p')
	{
		printf__putstr_fd("0x", 1);
		return (printf__putnbr_base(va_arg(*ap, size_t), BASE16LOW) + 2);
	}
	if (c == 'd' || c == 'i')
		return (printf__putnbr_fd(va_arg(*ap, int), 1));
	if (c == 'u')
		return (printf__putnbr_base(va_arg(*ap, unsigned int), BASE10));
	if (c == 'x')
		return (printf__putnbr_base(va_arg(*ap, unsigned int), BASE16LOW));
	if (c == 'X')
		return (printf__putnbr_base(va_arg(*ap, unsigned int), BASE16UP));
	if (c == '%')
		return (printf__putchar_fd('%', 1));
	return (printf__putchar_fd(c, 1));
}

/**
 * @brief Produce output according to a format specified in the string s and
 * write this output to stdout.
 * @param s The format string.
 * @return The number of characters printed if the function returns
 * successfully, else it returns a negative value.
 */
int	f_printf(const char *s, ...)
{
	int		r;
	va_list	ap;

	if (!s || write(1, 0, 0) < 0)
		return (-1);
	if (!*s)
		return (0);
	r = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
			r += printf__putchar_fd(*s, 1);
		else
			r += printf__subperc(*++s, &ap);
		if (!*s++)
			break ;
	}
	va_end(ap);
	return (r);
}
