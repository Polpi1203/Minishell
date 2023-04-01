/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 07:01:30 by polpi             #+#    #+#             */
/*   Updated: 2023/03/30 07:28:23 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polpi.h"

int	signal_init(int sig)
{
	struct sigaction sa;

    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sigaddset(&sa.sa_mask, SIGQUIT);
	if (sigaction(SIGINT, &sig, NULL) != 0)
		perror("Error with SIGINT");
	if (sigaction(SIGQUIT, &sig, NULL) != 0)
		perror("Error with SIGQUIT");
}