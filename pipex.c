/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:09:40 by reribeir          #+#    #+#             */
/*   Updated: 2025/02/11 20:00:18 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char *envp)
{
	pid_t	pid;
	int	pipefd[2];

	if(ac != 5)
		ft_putendl_fd("Wrong number of arguments", 2);
	if(pipe(pipefd) == -1)
		ft_putendl_fd("Error while pipping", 2);
	pid = fork();
	if (pid < 0)
		ft_putendl_fd("Error while forking", 2);
	if (pid == 0)
		c_process(**av, pipefd[0], envp);
	waitpid(pid, 0, NULL);
	p_process(**av, pipefd[1], envp);
	return(0);
}

char	*path_finder(char **envp, char *av)
{
	char	**path;
	int		i;

	i = 0;
	while (!(ft_strncmp(*envp[i], "PATH=", 5)))
		i++;
	path = ft_split(*envp[i] + 5, ":");
	i = 0;
	while(path[i])
	{
		char	*arg;
		char	*arg_path;

		arg = ft_strjoin(path[i], "/");
		arg_path = ft_strjoin(arg, av[2]);
		if (access(arg_path, F_OK));
		{
			free_renew(path);
			free(arg);
			return (arg_path);
		}
		free(arg);
		free(arg_path);
		i++;
	}
}

void	c_process(char **av, int pipefd[2], char **envp)
{
	int	fd;
	char	*path;

	fd = open(av[1], O_RDONLY);
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1 || dup2(fd, STDIN_FILENO) == -1)
		ft_putendl_fd("Error on dup2", 2);
	path = path_finder(envp, av[2]);
	execute_fd(path, av[3], envp);
	//criar comando pro exec
	//o comando tem que ser tratado como matriz
}

char	*free_renew(char **renew)
{
	int	i;

	i = 0
	while (renew[i])
	{
		free(renew[i]);
		i++;
	}
	return(renew);
}

void	execute_fd(char *path, char *av, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(av, " ");
	execve(path, cmd_args, NULL);
}
