/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:39:01 by polpi             #+#    #+#             */
/*   Updated: 2023/04/04 07:49:53 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// A DELETE UNIQUEMENT POUR TESTER

int main() 
{
    char    *tmp_cmd;
    char input[1024];
    t_token token;
    token.arg = malloc(128 * sizeof(char *));

    while (1) {
        printf("mibhgkhnishell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Supprimer le caractère de nouvelle ligne
        input[strcspn(input, "\n")] = 0;
        printf("Ooooofefeofjeo");
        // Tokeniser l'entrée
        tmp_cmd = strtok(input, " ");
        if (tmp_cmd == NULL) {
            continue;
        }

        // Obtenir les arguments
        int i = -1;
        while (tmp_cmd != NULL) {
            token.arg[++i] = tmp_cmd;
            tmp_cmd = strtok(NULL, " ");
        }
        token.arg[i] = NULL;

        // Exécuter la commande
        execute_command(&token);
    }
    free (token.arg);
    return 0;
}
