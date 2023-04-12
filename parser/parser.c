#include "../minishell.h"

/**
 * Takes the input and parses it to then call the
 * appropriate functions to execute the needed commands
 *
 * @param [*input] the input to parse.
 * @param [*envi] our own environment.
 *
 * @return returns nothing but calls the needed function
 * to execute the parsing
 */
void	parser(char	*input, t_env *envi)
{
	t_token	*head;
	int		i;

	i = 0;
	head = NULL;
	while (input[i])
	{
		i = sequencer(&head, input, envi, i);
		if (input[i] == '|')
			i++;
	}
	printf("head cmd : %s\n", head->cmd);
	if (check_exec(head) == 1)
		execute_command(head);
	execut_extern_command(head);
	// Il faut que je remplace son execution par la mienne !!!!!!!!!!! 
	// replace_usd(head);
	// execution(head);
	free_token(&head);
}
