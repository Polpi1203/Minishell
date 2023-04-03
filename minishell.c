/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:39:01 by polpi             #+#    #+#             */
/*   Updated: 2023/04/03 20:49:01 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// A DELETE UNIQUEMENT POUR TESTER

int main() 
{
    char input[1024];
    t_token token;
    token.arg = malloc(128 * sizeof(char *));

    while (1) {
        printf("minishell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Supprimer le caractère de nouvelle ligne
        input[strcspn(input, "\n")] = 0;

        // Tokeniser l'entrée
        token.cmd = strtok(input, " ");
        if (token.cmd == NULL) {
            continue;
        }

        // Obtenir les arguments
        printf("token.cmd : %s\n", token.cmd);
        int i = -1;
        while (token.cmd != NULL) {
            token.arg[++i] = token.cmd;
            token.cmd = strtok(NULL, " ");
        }
        token.arg[i] = NULL;
        printf("token.cmd : %s\n", token.cmd);

        // Exécuter la commande
        execute_command(&token);
    }
    free (token.arg);
    return 0;
}

// // int	main(int ac, char **av, char **env)
// // {
// // 	char			*input;
// // 	struct termios	termios;

// // 	(void)ac;
// // 	(void)av;
// // 	(void)env;
// // 	if ((tcgetattr(STDIN_FILENO, &termios)) == -1)
// // 		exit(EXIT_FAILURE);
// // 	termios.c_lflag &= ~(ECHOCTL);
// // 	if ((tcsetattr(STDIN_FILENO, TCSANOW, &termios)) == -1)
// // 		exit(EXIT_FAILURE);
// // 	input = "lol";
// // 	while (input != NULL)
// // 	{
// // 		signals_init();
// // 		input = readline("Minishell > ");
// // 		parser(input);
// // 		add_history(input);
// // 	}
// // 	free(input);
// // 	return (0);
// }