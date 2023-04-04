/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:32:12 by polpi             #+#    #+#             */
/*   Updated: 2023/04/04 11:09:20 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Insérez ici les définitions des fonctions builtin_cd, builtin_pwd, builtin_echo et builtin_exit

void execute_command(t_token *token) 
{
    printf("builtin-token.arg[0] : %s\n", token->arg[0]);
    if (ft_strcmp(token->arg[0], "cd") == 0) {
        builtin_cd(token);
    } else if (ft_strcmp(token->arg[0], "pwd") == 0) {
        builtin_pwd(token);
    } else if (ft_strcmp(token->arg[0], "echo") == 0) {
        builtin_echo(token);
    } else if (ft_strcmp(token->arg[0], "exit") == 0) {
        builtin_exit(token);
    } else if (ft_strcmp(token->arg[0], "env") == 0) {
        builtin_env(token);
    } else if (ft_strcmp(token->arg[0], "unset") == 0) {
        builtin_unset(token);
    // } else if (ft_strcmp(token->arg[0], "ls") == 0) { // A déplacer !! 
    //     execut_extern_command(token);
    } else {
        printf("Commande non reconnue: %s\n", token->cmd);
    }
}

