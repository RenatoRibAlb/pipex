/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:38:08 by reribeir          #+#    #+#             */
/*   Updated: 2025/02/14 13:44:48 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*free_renew(char **renew)
{
	int	i;

	i = 0;
	while(renew[i])
	{
		free(renew[i]);
		i++;
	}
	return(*renew);
}

char	*path_finder(char **envp, char *av)
{
	char	**path;
	int		i;

	i = 0;
	while (!(ft_strncmp(envp[i], "PATH=", 5)))
		i++;
	path = ft_split(envp[i + 5], ':');
	while(path[i])
	{
		char	*arg;
		char	*arg_path;

		arg = ft_strjoin(path[i], "/");
		arg_path = ft_strjoin(arg, av);
		if (access(arg_path, F_OK))
		{
			free_renew(path);
			free(arg);
			return (arg_path);
		}
		free(arg);
		free(arg_path);
		i++;
	}
	return(NULL);
}
