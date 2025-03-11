/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:09:40 by reribeir          #+#    #+#             */
/*   Updated: 2025/03/11 13:48:29 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	pipe1[2];
	int	pid1;
	int	pid2;

	if (ac != 5)
		ft_putstr_fd("Wrong number of arguments", 2);
	if (pipe(pipe1) == -1)
		ft_putstr_fd("Error while pipping", 2);
	pid1 = fork();
	if (pid1 == 0)
		c_process(av, pipe1, envp);
	pid2 = fork();
	if (pid2 == 0)
		p_process(av, pipe1, envp);
	close(pipe1[0]);
	close(pipe1[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

void	c_process(char *av[], int *in_pipe, char **envp)
{
	int		fd;
	char	*path_c;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Error opening input file", 2);
	dup2(fd, STDIN_FILENO);
	dup2(in_pipe[1], STDOUT_FILENO);
	close(in_pipe[0]);
	close(in_pipe[1]);
	close(fd);
	path_c = path_finder(envp, av[2]);
	if (path_c == NULL)
		ft_putstr_fd("Error finding path", 2);
	execute_fd(path_c, av[2], envp);
}

void	p_process(char *av[], int *in_pipe, char **envp)
{
	int		fd;
	char	*path_p;

	fd = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		ft_putstr_fd("Error opening output file", 2);
	dup2(in_pipe[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(in_pipe[0]);
	close(in_pipe[1]);
	close(fd);
	path_p = path_finder(envp, av[3]);
	if (path_p == NULL)
		ft_putstr_fd("Error finding path", 2);
	execute_fd(path_p, av[3], envp);
}

void	execute_fd(char *path, char *av, char **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(av, ' ');
	if (execve(path, cmd_args, envp) == -1)
		ft_putstr_fd("Error while exec", 2);
}
