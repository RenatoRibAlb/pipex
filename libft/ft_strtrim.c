/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:10:10 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/18 10:31:35 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	n = ft_strlen(s1);
	while (start_set(s1[i], set) == 1)
		i++;
	while (start_set(s1[n - 1], set) == 1)
		n--;
	if ((n - i) <= 0)
		return (ft_strdup(""));
	dst = ft_calloc ((n - i) + 1, sizeof(char));
	if (!dst)
		return (NULL);
	n = (n - i);
	while (j < n)
		dst[j++] = s1[i++];
	return (dst);
}
/*int	main(void)
{
#include <stdio.h>
	char	i[] = " xlasjdsavahs x  -xx";
	char	r[] = " x";

	printf("%s", ft_strtrim(i, r));
}*/
