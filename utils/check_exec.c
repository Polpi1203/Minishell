/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:01:45 by polpi             #+#    #+#             */
/*   Updated: 2023/04/04 11:23:12 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_exec(t_token *token)
{
    if (ft_strcmp(token->cmd, "echo") == 0 \
        || ft_strcmp(token->cmd, "cd") == 0 \
        || ft_strcmp(token->cmd, "env") == 0 \
        || ft_strcmp(token->cmd, "exit") == 0 \
        || ft_strcmp(token->cmd, "pwd") == 0 \
        || ft_strcmp(token->cmd, "unset") == 0)
    {
        return 1;
    }
    return 0;
}