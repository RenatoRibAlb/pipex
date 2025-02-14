/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:03:49 by reribeir          #+#    #+#             */
/*   Updated: 2025/02/14 10:13:27 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printpointer(void *addr)
{
	unsigned long	n;
	int				i;

	n = (unsigned long)addr;
	i = 0;
	if (!addr)
		return (ft_printstring("(nil)"));
	i += write (1, "0x", 2);
	i += ft_printhex(n, "0123456789abcdef");
	return (i);
}
