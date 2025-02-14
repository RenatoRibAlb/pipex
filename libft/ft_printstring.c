/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:50:24 by reribeir          #+#    #+#             */
/*   Updated: 2025/02/14 10:15:37 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstring(char *c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!c)
		return (ft_printstring("(null)"));
	while (c[i] != '\0')
	{
		count += write(1, &c[i], 1);
		i++;
	}
	return (ft_strlen(c));
}
