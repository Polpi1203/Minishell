/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:59:48 by polpi             #+#    #+#             */
/*   Updated: 2023/04/03 07:00:52 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int builtin_exit(t_token *token) 
{
    int exit_code = 0;
    if (token->arg[1] != NULL) {
        exit_code = atoi(token->arg[1]);
    }
    exit(exit_code);
}
