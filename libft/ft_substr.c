/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:39:09 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/14 16:16:43 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*verify(char *dest)
{
	dest = malloc(1);
	*dest = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	j;

	dest = NULL;
	i = 0;
	j = start;
	if (!s)
		return (NULL);
	if (len == 0)
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (verify(dest));
	while (s[start++] != '\0' && i < len)
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[j] && i < len)
		dest[i++] = s[j++];
	dest[i] = '\0';
	return (dest);
}
/*int	main(void)
{
	#include <stdio.h>
	char	*f;

	f = ft_substr("Renato", 2, 4);
	printf("%s", f);
}*/
