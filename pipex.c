/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:46:04 by mkokorev          #+#    #+#             */
/*   Updated: 2024/03/21 12:23:20 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		pipefd[2];
	int		forkid;

	if (argc != 5)
		return (errors(1));
	if (pipe(pipefd) == -1)
		return (errors(2));
	forkid = fork();
	if (forkid < 0)
		return (errors(3));
	if (forkid == 0)
	{
		if (!(child_process(argv, pipefd)))
			return (0);
	}
	else
	{
		close(pipefd[1]);
		wait(NULL);
		parent_process(argv, pipefd);
	}
	return (0);
}
