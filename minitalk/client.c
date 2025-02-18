/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekibar <ekibar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:20:45 by ekibar          #+#    #+#             */
/*   Updated: 2025/02/15 14:20:46 by ekibar         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(char a, int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((a << i) & 128)
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_printf("Error: Uncorrect PID\n");
				exit(1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_printf("Error: Uncorrect PID\n");
				exit(1);
			}
		}
		i++;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	i;

	server_pid = -1;
	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
		{
			ft_printf("Error: Invalid PID\n");
			exit (1);
		}
		while (argv[2][i])
		{
			send_message(argv[2][i], server_pid);
			i++;
		}
	}
	else
		ft_printf("Error: %s <Server_Pid> <Message>\n", argv[0]);
	return (0);
}
