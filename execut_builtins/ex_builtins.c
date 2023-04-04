/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:32:12 by polpi             #+#    #+#             */
/*   Updated: 2023/04/04 12:58:06 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Insérez ici les définitions des fonctions builtin_cd, builtin_pwd, builtin_echo et builtin_exit

void execute_command(t_token *token) 
{
	if (ft_strcmp(token->cmd, "cd") == 0)
		builtin_cd(token);
	else if (ft_strcmp(token->cmd, "pwd") == 0)
		builtin_pwd(token);
	else if (ft_strcmp(token->cmd, "echo") == 0)
		builtin_echo(token);
	else if (ft_strcmp(token->cmd, "exit") == 0)
		builtin_exit(token);
	else if (ft_strcmp(token->cmd, "env") == 0)
		builtin_env(token);
	else if (ft_strcmp(token->cmd, "unset") == 0)
		builtin_unset(token);
	// } else if (ft_strcmp(token->arg[0], "ls") == 0) { // A déplacer !! 
	//     execut_extern_command(token);
	else
		printf("Commande non reconnue: %s\n", token->cmd);
}

