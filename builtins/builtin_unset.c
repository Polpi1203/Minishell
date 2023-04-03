/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:59:53 by polpi             #+#    #+#             */
/*   Updated: 2023/04/03 07:00:00 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int builtin_unset(t_token *token)
{
    if (token->arg[1] == NULL) {
        fprintf(stderr, "unset: argument manquant\n");
        return 1;
    } else {
        if (unsetenv(token->arg[1]) != 0) {
            perror("unset");
        }
    }
    return 0;
}