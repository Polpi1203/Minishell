/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:44:26 by polpi             #+#    #+#             */
/*   Updated: 2023/04/01 08:57:07 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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