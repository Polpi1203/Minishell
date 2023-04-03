/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:59:39 by polpi             #+#    #+#             */
/*   Updated: 2023/04/03 07:20:32 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int builtin_cd(t_token *token) 
{
    write (1, "ok\n", 3);
    if (token->arg[1] == NULL) 
    {
        fprintf(stderr, "cd: argument manquant\n");
        return 1;
    } 
    else
    {
        if (chdir(token->arg[1]) != 0)
            perror("cd");
    }
    return 0;
}
