/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:09:56 by dbajeux           #+#    #+#             */
/*   Updated: 2024/07/30 17:25:05 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minitalk.h"

#include <signal.h>
#include <unistd.h>

void handler(int bit)
{
    
}

int main(void)
{
    ft_printf(" l'id processus de mon serveur est : %d",getpid());
    signal(SIGUSR1, handler);
    signal(SIGUSR2,handler);
    while (1)
        pause();
    return (0);
}
