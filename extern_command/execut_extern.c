/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut_extern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:52:28 by polpi             #+#    #+#             */
/*   Updated: 2023/04/12 09:21:14 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execut_extern_command(t_token *token)
{
	(void)token;
	char	**path;
	int		i;

	token->path_add = malloc(sizeof(char) * 1024);
	path = ft_split(getenv("PATH"), ':');
	if (!path)
		return (perror("The split function didn't work"));
	i = -1;
	// while (path[++i])
	// 	printf("path[i] : %s\n", path[i]);
	add_cmd_to_path_and_check(token, path);
	free (token->path_add);
}

void	add_cmd_to_path_and_check(t_token *token, char **path)
{
	int	i;

	i = -1;
	while (path[++i])
	{
		ft_strlcpy(token->path_add, path[i], sizeof(char) * ft_strlen(path[i]) + 1);
		ft_strlcat(token->path_add, "/", sizeof(char) * ft_strlen(path[i]) + 2);
		ft_strlcat(token->path_add, token->cmd, sizeof(char) * ft_strlen(path[i]) + ft_strlen(token->cmd) + 2);
		// printf("---------------------------------\n");
		// printf("path_add : %s\n", token->path_add);
		// printf("---------------------------------\n");
		if (access(token->path_add, X_OK) == 0)
		{
			fork_process(token);
		}
	}
}