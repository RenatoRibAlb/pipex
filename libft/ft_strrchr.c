/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:49:08 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/18 10:51:50 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	l = ft_strlen(s);
	while (l >= 0)
	{
		if (str[l] == (unsigned char)c)
		{
			str = str + l;
			return (str);
		}
		else
			l--;
	}
	return (NULL);
}
/*int	main(void)
{
	char	*k;

	k = ft_strrchr("Ronate", 'u');
	write(1, k, 1);
}*/
