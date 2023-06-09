/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 07:01:28 by polpi             #+#    #+#             */
/*   Updated: 2023/04/12 15:45:51 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signal_handle(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exit_code = 128 + SIGINT;
	}
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		g_exit_code = 128 + SIGQUIT;
	}
}