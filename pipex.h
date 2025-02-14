/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 07:02:50 by reribeir          #+#    #+#             */
/*   Updated: 2025/02/14 15:29:52 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "./libft/libft.h"

int	main(int ac, char **av, char **envp);

char	*path_finder(char **envp, char *av);

void	c_process(char **av, int in_pipe[2], char **envp);

void	p_process(char **av, int in_pipe[2], char **envp);

char	*free_renew(char **renew);

void	execute_fd(char *path, char *av, char **envp);

void	renew_pipe(int	fd[2]);

#endif
