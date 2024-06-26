/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:37:28 by mkokorev          #+#    #+#             */
/*   Updated: 2024/03/13 18:56:16 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*arr;

	arr = malloc(nmemb * size);
	if (!arr)
		return (0);
	ft_memset(arr, 0, nmemb * size);
	return (arr);
}
