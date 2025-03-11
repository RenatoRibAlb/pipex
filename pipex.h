/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reribeir <reribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 07:02:50 by reribeir          #+#    #+#             */
/*   Updated: 2025/03/11 12:08:30 by reribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "./libft/libft.h"

int		main(int ac, char **av, char **envp);

char	*path_finder(char **envp, char *av);

void	c_process(char **av, int *in_pipe, char **envp);

void	p_process(char **av, int *in_pipe, char **envp);

void	free_renew(char **renew1, char *renew2);

void	execute_fd(char *path, char *av, char **envp);

char	*check_access(char **paths, char *cmd);

#endif
