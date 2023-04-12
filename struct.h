/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:00:45 by polpi             #+#    #+#             */
/*   Updated: 2023/04/12 16:01:03 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_env
{
	int				alpha;
	char			*path;
	char			**var;
	struct s_env	*next;

}				t_env;

typedef struct s_token
{
	int					type;
	int					flag_env; //if == 1, then use env variables
	int					i;
	int					pos;
	int					env_len;
	int					file_type;
	int					fdwrite;
	int					fdread;
	char				*path_add;
	char				*cmd;
	char				**arg;
	t_env				*env;
	struct s_token		*next;
}				t_token;

enum e_token {
	COMMAND = 1,
	ARG = 2,
	PIPE = 3,
	R_LEFT = 4,		// <
	R_RIGHT = 5,	// >
	RR_LEFT = 6,	// <<
	RR_RIGHT = 7,	// >>
};