/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavast <rchavast@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-01 21:41:08 by rchavast          #+#    #+#             */
/*   Updated: 2026-05-01 21:41:08 by rchavast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putptr_hex(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_putptr_hex(address);
	return (count);
}
