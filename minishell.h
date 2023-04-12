/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:44:26 by polpi             #+#    #+#             */
/*   Updated: 2023/04/12 16:08:18 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>
#include <sys/param.h>
#include <errno.h>

#include "struct.h"
#include "../libft/srcs/libft.h"

extern int		g_exit_code;


//lexer.c

int				sequencer(t_token **head, char *input, t_env *envi, int index);
void			get_cmd(t_token *new, char *input);
void			get_redirection(t_token *new, char *input);
void			get_arg(t_token *new, char *input);
int				word_len(char *input, int i);


//lexer_utils.c

int				isredi(char c);
int				isdeli(char c, char flag);
int				ft_isaspace(char c);
void			space_index(t_token *new, char *input);
int				checkquotes(char *input, char quote, int i);
void			initialisation(t_token	*head);

//linked_list.c

void			add_token(t_token **head, char **command);
void			add_last(t_token **head, t_token *new);
t_token			*get_last(t_token *head);
void			print_list(t_token *head);

//get.c

void			get_word(t_token *new, char *input);
void			get_squote(t_token *new, char *input);
void			get_dquote(t_token *new, char *input);
int				mystrcspn(char *s, char *reject, int i);
int				env_handler(t_token *new, char *input, int j);


//redirection.c

void			r_left(t_token *new, char *input);
void			rr_left(t_token *new, char *input);	//TODO not finished
void			r_right(t_token *new, char *input);
void			rr_right(t_token *new, char *input);
char			*get_file(t_token *new, char *input);

//parser.c

void			parser(char *input, t_env *envi);

//execut_builtins

void execute_command(t_token *token);

//builtins

void	builtin_cd(t_token *token);
void	builtin_echo(t_token *token);
void	builtin_exit(t_token *token);
int builtin_pwd(t_token *token);
void	builtin_unset(t_token *token);
int builtin_env(t_token *token);

//Signals

void	signal_init(void);
void	signal_handle(int sig);

//external commands

void	execut_extern_command(t_token *token);
int		fork_process(t_token *token);
void	add_cmd_to_path_and_check(t_token *token, char **path);

//utils

int 	ft_strcmp(char *chain1, char *chain2);
int 	check_exec(t_token *token);
char	*ft_strlcpy_char(char *dst, char *src, int dstsize);
void	init_env(t_env **envi, char **env);
void	add_env(t_env **envi, char *env);
int		az_env(t_token *token);
void	env_init(t_token *token);
int		ft_switch_int(t_env *alpha, t_env *beta);

//free

void	free_token(t_token **head);
void	free_env(t_env **envi);