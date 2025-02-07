/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 07:39:14 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/18 10:22:55 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	r;
	int	s;

	s = 1;
	i = 0;
	r = 0;
	while ((nptr[i] > 7 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		s *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	}
	return (s * r);
}
/*int	main(void)
{
#include <stdio.h>
	char v[] = " ----++-9011";

	printf("%d",  ft_atoi(v));
}*/
