/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:59:39 by polpi             #+#    #+#             */
/*   Updated: 2023/04/12 18:35:17 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(t_token *token)
{
	printf("token->arg[0] : %s\n", token->arg[0]);
	if (token->arg[0] == NULL)
		printf("cd: argument manquant\n");
	else
	{
		if (chdir(token->arg[0]) != 0)
			perror("cd");
	}
}
