/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut_extern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:52:28 by polpi             #+#    #+#             */
/*   Updated: 2023/04/04 11:22:29 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execut_extern_command(t_token *token)
{
	write (1, "OK\n", 3);
	(void)token;
	char	**path;
	char	path_add[1024];
	int		i;

	path = ft_split(getenv("PATH"), ':');
	if (!path)
		return (perror("The split function didn't work"));
	i = -1;
	while (path[++i])
	{
		ft_strlcpy(path_add, path[i], sizeof(path_add));
		ft_strlcat(path_add, "/", sizeof(path_add));
		ft_strlcat(path_add, token->arg[0], sizeof(path_add));
		printf("--------path_add---------- : %s\n", path_add);
	}
	i = -1;
	while (path[++i])
		printf("path[i] : %s\n", path[i]);
}