/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:23:17 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/29 17:02:58 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long int c, char *str)
{
	int		i;

	i = 0;
	if (c >= 16)
		i += ft_printhex((c / 16), str);
	i += ft_printchar(str[c % 16]);
	return (i);
}
