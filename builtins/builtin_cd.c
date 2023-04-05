/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:59:39 by polpi             #+#    #+#             */
/*   Updated: 2023/04/05 18:14:37 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(t_token *token)
{
	if (token->arg[1] == NULL)
		printf("cd: argument manquant\n");
	else
	{
		if (chdir(token->arg[1]) != 0)
			perror("cd");
	}
}
