/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 07:15:33 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/18 10:50:52 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!*little || big == little)
		return ((char *)(big));
	while (big[++i] != '\0' && i < len)
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && i + j < len)
			{
				if (little[j + 1] == '\0')
					return ((char *)(big + i));
				j++;
			}
			j = 0;
		}
	}
	return (NULL);
}
/*int main()
{
#include <stdio.h>
	char s1[] = "estea";
	char s2[] = "te";

	printf("%s", ft_strnstr(s1, s2, 4));
}*/
