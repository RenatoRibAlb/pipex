/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:09:40 by reribeir          #+#    #+#             */
/*   Updated: 2025/02/14 14:22:37 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;
	int	pipe1[2];

	char	*path_p;

	if(ac != 5)
		ft_putendl_fd("Wrong number of arguments", 2);
	if(pipe(pipe1) == -1)
		ft_putendl_fd("Error while pipping", 2);
	pid = fork();
	if (pid < 0)
		ft_putendl_fd("Error while forking", 2);
	if (pid == 0)
	{
		c_process(**av, &pipe1[0], envp);
	}
	else
	{
		p_process(**av, &pipe1[1], envp);
	}
	return(0);
}

void	c_process(char *av[], int in_pipe[2], char **envp)
{
	int	fd;
	char	*path_c;

	close(in_pipe[0]);
	fd = open(av[1], O_RDONLY);
	if (dup2(in_pipe[1], STDOUT_FILENO) == -1 || dup2(fd, STDIN_FILENO) == -1)
		ft_putendl_fd("Error on child dup2", 2);
	path_c = path_finder(envp, av[2]);
	execute_fd(path_c, av[2], envp);
}

void	p_process(char *av[], int in_pipe[2], char **envp)
{
	int	fd;
	char *path_p;

	close(in_pipe[1]);
	fd = open(av[4], O_RDONLY);
	if (dup2(fd, STDOUT_FILENO) == -1 || dup2(in_pipe[0], STDIN_FILENO) == -1)
		ft_putendl_fd("Error on parent dup2", 2);
	path_p = path_finder(envp, av[3]);
	execute_fd(path_p, av[3], envp);
}

void	execute_fd(char *path, char *av, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(av, ' ');
	execve(path, cmd_args, envp);
}
