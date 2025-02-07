/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:05:35 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/08 22:44:43 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		c = (n % 10 + '0');
		write (fd, &c, 1);
	}
	if (n >= 0 && n <= 9)
	{
		c = (n % 10 + '0');
		write (fd, &c, 1);
		return ;
	}
}
/*int	main(void)
{
	int	v = -2147483648;

	ft_putnbr_fd(v, 1);
}*/
