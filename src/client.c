/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbajeux <dbajeux@student.19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:09:27 by dbajeux           #+#    #+#             */
/*   Updated: 2024/07/31 19:31:20 by dbajeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_byte(int bit, int pid)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(550);
}

void	send_msg(int pid, char *str)
{
	t_byte	byte;
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		byte.i = 0;
		byte.c = str[i];
		while (byte.i <= 7)
		{
			send_byte((byte.c >> byte.i) & 1, pid);
			byte.i++;
		}
		i++;
	}
	byte.c = 0;
	byte.i = 0;
	while (byte.i <= 7)
	{
		send_byte((byte.c >> byte.i) & 1, pid);
		byte.i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_atoi(argv[1]) < 1)
		{
			ft_printf("Error: Incorrect PID.");
			return (1);
		}
		send_msg(ft_atoi(argv[1]), argv[2]);
	}
	else
	{
		ft_printf("Error: Please enter the correct number of arguments./n");
		return (1);
	}
	return (0);
}