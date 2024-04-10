/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:57:25 by mkokorev          #+#    #+#             */
/*   Updated: 2024/03/21 13:14:29 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

int	cmd1(char **argv, int *pipefd, int infile)
{
	char	**cmd1;
	char	*arv[4];
	char	*path;
	int		output;

	output = dup(1);
	if (output == -1 || dup2(pipefd[1], 1) == -1 || dup2(infile, 0) == -1)
		return (7);
	dup2(infile, 0);
	cmd1 = ft_split(argv[2], ' ');
	path = ft_strjoin("/usr/bin/", cmd1[0]);
	arv[0] = path;
	if (cmd1[1])
		arv[1] = cmd1[1];
	else
		arv[1] = NULL;
	arv[2] = NULL;
	if (execve(path, arv, NULL) == -1)
	{
		dup2(output, 1);
		free(path);
		free_array(cmd1);
		return (8);
	}
	return (1);
}

int	child_process(char **argv, int *pipefd)
{
	int		infile;
	int		er;

	close(pipefd[0]);
	if (access(argv[1], F_OK) == -1)
		return (errors(4));
	if (access(argv[1], R_OK) == -1)
		return (errors(5));
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		return (errors(6));
	er = cmd1(argv, pipefd, infile);
	if (er == 8)
		return (errors(8));
	else if (er == 7)
		return (errors(7));
	close(infile);
	return (1);
}

int	parent_process(char **argv, int *pipefd)
{
	int		outfile;
	int		er;

	close(pipefd[1]);
	if (access(argv[4], F_OK) == -1)
		outfile = open(argv[4], O_WRONLY | O_CREAT);
	else
		outfile = open(argv[4], O_WRONLY | O_TRUNC);
	if (outfile == -1)
		return (errors(6));
	er = cmd2(argv, pipefd, outfile);
	if (er == 8)
		return (errors(8));
	else if (er == 7)
		return (errors(7));
	return (1);
}

int	cmd2(char **argv, int *pipefd, int outfile)
{
	char	**cmd1;
	char	*arv[4];
	char	*path;
	int		stout;

	stout = dup(1);
	if (stout == -1 || dup2(pipefd[0], 0) == -1 || dup2(outfile, 1) == -1)
		return (7);
	cmd1 = ft_split(argv[3], ' ');
	path = ft_strjoin("/usr/bin/", cmd1[0]);
	arv[0] = path;
	if (cmd1[1])
		arv[1] = cmd1[1];
	else
		arv[1] = NULL;
	arv[2] = NULL;
	if (execve(path, arv, NULL) == -1)
	{
		dup2(stout, 1);
		free(path);
		free_array(cmd1);
		return (8);
	}
	return (1);
}
