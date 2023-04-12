/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:59:53 by polpi             #+#    #+#             */
/*   Updated: 2023/04/12 09:29:29 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// A faire

void builtin_unset(t_token *token)
{
	if (token->arg[1] == NULL)
	{
		printf("unset: argument manquant\n");
	}
	else
	{
		// Parcourir la liste des variables d'environnement et supprimer la variable spécifiée
		// Libérer la mémoire allouée pour cette variable
	}
}
