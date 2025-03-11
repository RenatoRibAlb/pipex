/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:38:08 by reribeir          #+#    #+#             */
/*   Updated: 2025/03/11 13:49:12 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_renew(char **renew1, char *renew2)
{
	int	i;

	i = 0;
	free(renew2);
	while (renew1[i])
	{
		free(renew1[i]);
		i++;
	}
}

char	*path_finder(char **envp, char *av)
{
	char	**paths;
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	while ((ft_strncmp(envp[i], "PATH=", 5)) != 0)
		i++;
	path = envp[i];
	cmd = ft_split(av, ' ');
	paths = ft_split(path + 5, ':');
	return (check_access(paths, cmd[0]));
}

char	*check_access(char **paths, char *cmd)
{
	char	*arg;
	char	*arg_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		arg = ft_strjoin(paths[i], "/");
		arg_path = ft_strjoin(arg, cmd);
		if (access(arg_path, F_OK | X_OK) == 0)
		{
			free_renew(paths, arg);
			return (arg_path);
		}
		free(arg);
		free(arg_path);
		i++;
	}
	return (NULL);
}
