/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:18:51 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/14 19:43:54 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size / size != nmemb)
		return (NULL);
	s = malloc(size * nmemb);
	if (!s)
		return (NULL);
	ft_bzero(s, (nmemb * size));
	return (s);
}
/*int main(void)
{
    int* p2 = ft_calloc(1, sizeof(int[4]));
	int	n;

	n = 0;
	if (p2)
	{
		while (n < 4)
		{
			printf("p2[%d] == %d\n", n, p2[n]);
			n++;
		}
	}
}
*/
