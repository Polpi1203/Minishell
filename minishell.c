/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:39:01 by polpi             #+#    #+#             */
/*   Updated: 2023/03/30 07:00:16 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	main(int ac, char **av, char **env)
{
	char			*input;
	struct termios	termios;

	(void)ac;
	(void)av;
	(void)env;
	if ((tcgetattr(STDIN_FILENO, &termios)) == -1)
		exit(EXIT_FAILURE);
	termios.c_lflag &= ~(ECHOCTL);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &termios)) == -1)
		exit(EXIT_FAILURE);
	input = "lol";
	while (input != NULL)
	{
		signals_init();
		input = readline("Minishell > ");
		parser(input);
		add_history(input);
	}
	free(input);
	return (0);
}