/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:46:34 by mkokorev          #+#    #+#             */
/*   Updated: 2024/03/21 11:44:36 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./printf/ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

void	free_array(char **cmd);

int		errors(int error_code);

int		child_process(char **argv, int *pipefd);

int		parent_process(char **argv, int *pipefd);

int		cmd2(char **argv, int *pipefd, int infile);

#endif
