/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:09:40 by reribeir          #+#    #+#             */
/*   Updated: 2025/02/14 16:14:26 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;
	int	pipe1[2];
	int	i;

	i = 0;
	if(ac != 5)
		ft_putendl_fd("Wrong number of arguments", 2);
	if(pipe(pipe1) == -1)
		ft_putendl_fd("Error while pipping", 2);
	if (pid == 0)
		c_process(av, &pipe1[0], envp);
	else
		p_process(av, &pipe1[1], envp);
	return(0);
}

void	c_process(char *av[], int in_pipe[2], char **envp)
{
	int	fd;
	int	pid;
	char	*path_c;

	pid = fork();
	if (pid < 0)
		ft_putendl_fd("Error while forking", 2);
	if (pid == 0)
	{
		close(in_pipe[1]);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			ft_putendl_fd("Error on child dup2", 2);
		dup2(fd, STDIN_FILENO);
		dup2(in_pipe[0], STDOUT_FILENO);
		path_c = path_finder(envp, av[2]);
		execute_fd(path_c, av[2], envp);
	}
	renew_pipe(in_pipe);
}

void	p_process(char *av[], int in_pipe[2], char **envp)
{
	int	fd;
	int	pid;
	char *path_p;

	pid = fork();
	if (pid < 0)
		ft_putendl_fd("Error while forking", 2);
	if (pid == 0)
	{
		close(in_pipe[0]);
		fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC);
		if (fd == -1)
			ft_putendl_fd("Error on parent dup2", 2);
		dup2(in_pipe[1], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		path_p = path_finder(envp, av[3]);
		execute_fd(path_p, av[3], envp);
	}
	renew_pipe(in_pipe);
}

void	execute_fd(char *path, char *av, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(av, ' ');
	execve(path, cmd_args, envp);
}
