/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:07:18 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/17 16:35:25 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int k)
{
	long long	count;

	count = 0;
	while (k != 0)
	{
		k = k / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			j;
	long long	nb;

	j = int_len(n);
	nb = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		j += 1;
		str = malloc (sizeof(char) * (j + 1));
		nb *= -1;
		str[0] = '-';
	}
	else
		str = malloc (sizeof(char) * (j + 1));
	str[j] = '\0';
	j = j - 1;
	while (nb != 0)
	{
		str[j--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
/*int	main(void)
{
	int	h = -2147483648;
	printf("%s", ft_itoa(h));
}*/
