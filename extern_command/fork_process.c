/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:45:40 by polpi             #+#    #+#             */
/*   Updated: 2023/04/04 14:06:55 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	fork_process(t_token *token)
{
	char *const envp[] = {"PATH", NULL};
	pid_t pid = fork();

	if (pid < 0)
		perror("fork");
	else if (pid == 0) // Dans le children process
	{
		execve(token->path_add, token->arg, envp);
		perror("execve");
		exit(1);
	} 
	else 
	{
		int status;
		waitpid(pid, &status, 0); // Attendre que le children process se termine, sinon le programme ne fonctionne plus apres l'execution de ls
	}
	return 0;
}