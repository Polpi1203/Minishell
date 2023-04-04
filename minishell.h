/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:44:26 by polpi             #+#    #+#             */
/*   Updated: 2023/04/04 13:22:33 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/srcs/libft.h"

typedef struct s_token
{
	int					type;
	int					flag_env; //if == 1, then use env variables
	int					i;
	int					fdwrite;
	int					fdread;
	char				*cmd;
	char				**arg;
	struct s_token		*next;
	struct s_token		*prev;
}				t_token;


//execut_builtins

void execute_command(t_token *token);

//builtins

int builtin_cd(t_token *token);
void	builtin_echo(t_token *token);
void	builtin_exit(t_token *token);
int builtin_pwd(t_token *token);
int builtin_unset(t_token *token);
int builtin_env(t_token *token);

//external commands

void	execut_extern_command(t_token *token);

//utils

int 	ft_strcmp(char *chain1, char *chain2);
int 	check_exec(t_token *token);
char	*ft_strlcpy_char(char *dst, char *src, int dstsize);