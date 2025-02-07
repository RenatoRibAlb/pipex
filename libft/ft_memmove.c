/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:24:02 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/18 09:56:56 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*s;
	unsigned char	*d;

	i = n - 1;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (d > s)
	{
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (d);
}
/*int	main(void)
{
#include <stdio.h>
	char b[9] = "Renato";

	printf("%s\n", (char *)ft_memmove(b + 4, b, 2));
	printf("%s", b);
}*/
