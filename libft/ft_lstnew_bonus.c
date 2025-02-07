/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:34:14 by reribeir          #+#    #+#             */
/*   Updated: 2025/01/14 14:26:16 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc (sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*int	main(void)
{
#include <stdio.h>
	t_list	*a;

	a = ft_lstnew("Renato");
	printf("node a = %p\n", a);
	t_list	*b;

	b = ft_lstnew("Renato2");
	printf("node b = %p", b);

}
*/
