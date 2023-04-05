/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:59:51 by polpi             #+#    #+#             */
/*   Updated: 2023/04/05 18:13:52 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_pwd(t_token *token)
{
	(void)token;
	char	cwd[1024];

	if (getcwd(cwd, 1024) != NULL)
		printf("%s\n", cwd);
	else
		perror("pwd");
	return (0);
}
