/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:27:10 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/18 10:45:25 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*void	uppersc(unsigned int nb, char *src)
{
	nb = 0;
	if (src[nb] >= 'a' && src[nb] <= 'z')
		src[nb] -= 32;
}
int	main(void)
{
	char v[] = "renato";
	ft_striteri(v, uppersc);
	printf("%s", v);
}*/
