/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 06:52:30 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/14 11:31:31 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*s;
	size_t			i;

	p = (unsigned char *)s1;
	s = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p[i] == s[i])
			i++;
		else if (p[i] < s[i])
			return (-1);
		else if (p[i] > s[i])
			return (1);
	}
	return (0);
}
/*int	main(void)
{
	#include <stdio.h>
	#include <string.h>

	//const char	*r1 = "127";
	//const char	*r2 = "42";
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	printf("%d\n", ft_memcmp(s2, s3, 4));
}*/
