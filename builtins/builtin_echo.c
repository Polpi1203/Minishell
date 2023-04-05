/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:59:40 by polpi             #+#    #+#             */
/*   Updated: 2023/04/05 18:09:48 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_echo(t_token *token)
{
	int	i;

	i = 1;
	while (token->arg[i])
	{
		printf("%s", token->arg[i]);
		if (token->arg[i + 1] != NULL)
			printf(" ");
		i++;
	}
	printf("\n");
}
