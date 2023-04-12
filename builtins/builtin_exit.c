/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:59:48 by polpi             #+#    #+#             */
/*   Updated: 2023/04/12 18:31:25 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_exit(t_token *token)
{
	int	exit_code;

	exit_code = 0;
	if (token->arg[0] != NULL)
		exit_code = ft_atoi(token->arg[0]);
	exit(exit_code);
}
