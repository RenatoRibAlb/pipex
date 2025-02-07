/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:24:59 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/17 15:34:36 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("Renato");
	b = ft_lstnew("Renato2");
	ft_lstadd_front(&a, b);
	printf("%d", ft_lstsize(b));
}*/
