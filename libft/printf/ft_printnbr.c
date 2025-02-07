/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:08:13 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/29 16:59:46 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long int c)
{
	char			str;
	long long		i;

	i = 0;
	if (c < 0)
	{
		c = -c;
		i += write(1, "-", 1);
	}
	if (c > 9)
	{
		i += ft_printnbr((c / 10));
		str = (c % 10 + '0');
		i += write (1, &str, 1);
	}
	if (c >= 0 && c <= 9)
	{
		str = (c % 10 + '0');
		i += write (1, &str, 1);
	}
	return (i);
}
