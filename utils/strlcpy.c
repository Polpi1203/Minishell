/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:45:17 by polpi             #+#    #+#             */
/*   Updated: 2023/04/04 12:56:07 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strlcpy_char(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize == 0)
		return (src);
	while (src[i] != '\0' && i <= dstsize - 1)
	{
		dst[i] = src[i];
		i++;
		//write (1, "OK\n", 3);
	}
	dst[i] = '\0';
	return (dst);
}