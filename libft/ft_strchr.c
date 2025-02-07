/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:15:57 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/14 11:40:46 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (c == 0)
		return (str + ft_strlen(str));
	while (*str)
	{
		if (*str == (unsigned char)c)
			return (str);
		else
			str = str + 1;
	}
	return (NULL);
}
/*int	main(void)
{
	char	*k;

	k = ft_strchr("Ronate", 'u');
	write(1, k, 6);
}*/
