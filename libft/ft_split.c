/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:20:26 by reribeir          #+#    #+#             */
/*   Updated: 2025/02/14 10:25:49 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static char	*word_find(char const *s, char c, int *i)
{
	int		start;
	int		j;
	char	*str;

	j = 0;
	while (s[*i] == c)
		*i = *i + 1;
	start = *i;
	while (s[*i] != c && s[*i] != '\0')
		*i = *i + 1;
	str = malloc ((sizeof(char) * (*i - start)) + 1);
	if (!str)
		return (NULL);
	while (s[start] != c && s[start] != '\0')
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		arri;
	int		j;
	char	**arr;
	char	*src;
	int		i;

	if (!s)
		return (NULL);
	arri = 0;
	i = 0;
	src = (char *)s;
	j = word_count(src, c);
	arr = malloc (sizeof(char *) * (j + 1));
	if (!arr)
		return (NULL);
	while (arri < j)
	{
		arr[arri] = word_find(s, c, &i);
		arri++;
	}
	arr[arri] = NULL;
	return (arr);
}
/*int	main(void)
{
	int		i;
	char	src[] = "Agario O Melhor";
	char	es = ' ';
	char	**f;

	f = ft_split(src, es);
	i = 0;
	while (i < word_count(src, es))
	{
		printf("Palavra[%i] = %s\n", i, f[i]);
		i++;
	}
}*/
