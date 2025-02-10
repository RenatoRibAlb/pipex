/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:09:40 by reribeir          #+#    #+#             */
/*   Updated: 2025/02/10 15:22:52 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char *envp)
{
	int	fd;
	pid_t	pid;
	pid_t	pipe1[2];

	if(ac != 5)
		return(ft_printf("Error"));
	pid = fork();
	if (pid < 0)
		ft_printf("Error while forking");
	if (pid == 0)
		c_process(*av[2], &pipe, envp);
	
	return(0);
}

