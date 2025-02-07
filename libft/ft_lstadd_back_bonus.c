/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:43:26 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/18 09:34:24 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		a = *lst;
		while (a->next != NULL)
			a = a->next;
		a->next = new;
	}
	new->next = NULL;
}
