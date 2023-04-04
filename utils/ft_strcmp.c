/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:11:42 by polpi             #+#    #+#             */
/*   Updated: 2023/04/04 11:19:11 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_strcmp(char *chain1, char *chain2)
{
	int i;

	i = -1;
	while (chain1[++i])
	{
		if (chain1[i] != chain2[i])
			return 1;
	}
	return 0;
}

// int main(int ac, char **av)
// {
// 	(void)ac;

// 	printf("strcmp : %i\n", ft_strcmp(av[1], av[2]));
// }