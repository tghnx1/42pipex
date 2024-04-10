/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:00:26 by mkokorev          #+#    #+#             */
/*   Updated: 2024/03/21 13:14:15 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	errors(int error_code)
{
	if (error_code == 1)
		ft_printf("wrong number of arguments\n");
	if (error_code == 2)
		ft_printf("error to open a pipe\n");
	if (error_code == 3)
		ft_printf("error to fork\n");
	if (error_code == 4)
		ft_printf("no such file or directory\n");
	if (error_code == 5)
		ft_printf("permission denied\n");
	if (error_code == 6)
		ft_printf("failed to open the file\n");
	if (error_code == 7)
		ft_printf("failed to change a file's descriptor\n");
	if (error_code == 8)
		ft_printf("command is not found\n");
	return (0);
}
