/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 08:45:14 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/02 09:41:50 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*ns;

	i = 0;
	len = 0;
	if ((char *)s1 && (char *)s2)
		len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	ns = malloc(len * sizeof(char));
	if (!ns)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		ns[len] = s1[len];
		len++;
	}
	while (s2[i] != '\0')
	{
		ns[len] = s2[i];
		i++;
		len++;
	}
	ns[len] = '\0';
	return (ns);
}
/*int	main(void)
{
#include <stdio.h>
	const char a[] = "agua";
	const char b[] = "";
	printf("%s", ft_strjoin(a, b));
}*/
