/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:39:01 by polpi             #+#    #+#             */
/*   Updated: 2023/04/04 13:16:37 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// A DELETE UNIQUEMENT POUR TESTER

int main() 
{
    t_token token;
    char    *cmd_tmp;
    char    input[1024];
    token.arg = malloc(128 * sizeof(char *));

    while (1) {
        printf("minishell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        token.cmd = malloc(sizeof(char) * ft_strlen(input));
        cmd_tmp = malloc(sizeof(char) * ft_strlen(input));
        // Supprimer le caractère de nouvelle ligne
        input[strcspn(input, "\n")] = 0;
        //ft_strlcpy_char(cmd_tmp, input, ft_strlen(input));
        
        //Tokeniser l'entrée
        token.arg = ft_split(input, ' ');
        ft_strlcpy_char(token.cmd, token.arg[0], ft_strlen(token.arg[0]));
        int i = -1;
        while (token.arg[++i])
            printf("token[i] -> %s\n", token.arg[i]);

        // Obtenir les arguments
        // int i = -1;
        // while (tmp_cmd != NULL) {
        //     token.arg[++i] = tmp_cmd;
        //     tmp_cmd = strtok(NULL, " ");
        // }

        //printf("token.arg[0] -> %s\n", token.arg[0]);

        //execute cmd
        if (check_exec(&token) == 1)
            execute_command(&token);
        else
            execut_extern_command(&token);
    }
    free (token.arg);
    free (token.cmd);
    free (cmd_tmp);
    return 0;
}
