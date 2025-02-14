/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:17:30 by reribeir          #+#    #+#             */
/*   Updated: 2025/02/14 10:13:32 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunsigned(unsigned long int c)
{
	unsigned int	i;
	char			str;

	i = 0;
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
