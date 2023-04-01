/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:32:12 by polpi             #+#    #+#             */
/*   Updated: 2023/04/01 09:35:53 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Insérez ici les définitions des fonctions builtin_cd, builtin_pwd, builtin_echo et builtin_exit

void execute_command(t_token *token) {
	printf("token->cmd : %s\n", token->cmd);
	if (strcmp(token->cmd, "cd") == 0) {
		write (1, "ex_cd\n", 6);
		builtin_cd(token);
	// } else if (strcmp(token->cmd, "pwd") == 0) {
	// 	builtin_pwd();
	// } else if (strcmp(token->cmd, "echo") == 0) {
	// 	builtin_echo(token->arg);
	// } else if (strcmp(token->cmd, "exit") == 0) {
	// 	if (builtin_exit() == -1) {
	// 		exit(0);
	// 	}
	} else {
		printf("Commande non reconnue: %s\n", token->cmd);
	}
}

