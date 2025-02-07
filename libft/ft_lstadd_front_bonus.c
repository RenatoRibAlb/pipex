/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:11:32 by reribeir          #+#    #+#             */
/*   Updated: 2024/10/17 19:08:19 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
	{
		lst = &new;
		return ;
	}
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*int	main(void)
{
	t_list	**arr;
	t_list	*a;
	t_list	*b;

	arr = (t_list **)malloc( 2 * sizeof(t_list *));
	a = ft_lstnew("Renato");
	b = ft_lstnew("Renato2");
	*arr = a;
	ft_lstadd_front(arr, b);
	printf("%p\n", b);
	printf("%p\n", b->next);
	printf("%p\n", a);
	printf("%p", *arr);
}*/
