/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:39:21 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/18 10:34:05 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cmp;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	cmp = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == cmp)
		{
			str = str + i;
			return ((void *)str);
		}
		else
			i++;
	}
	return (NULL);
}
/*int	main(void)
{
	char	*k;

	k = ft_memchr("Ronate", 'o', 3);
	write(1, k, 1);
}*/
