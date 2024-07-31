/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:09:56 by dbajeux           #+#    #+#             */
/*   Updated: 2024/07/31 19:29:55 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_byte	byte;
void	init_byte(t_byte *byte)
{
	byte->c = 0;
	byte->i = 0;
}
void	handler(int signal)
{
	if (signal == SIGUSR1)
		byte.c |= (1 << byte.i);
	byte.i++;
	if (byte.i == 8)
	{
		if (byte.c == 0)
			ft_putchar_fd('\n', 1);
		ft_putchar_fd(byte.c, 1);
		init_byte(&byte);
	}
}

int	main(void)
{
	init_byte(&byte);
	ft_printf(" l'id processus de mon serveur est : %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
