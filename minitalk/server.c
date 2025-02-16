GNU nano 7.2                                                                                                                        server.c                                                                                                                                 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekibar <ekibar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:20:45 by ekibar          #+#    #+#             */
/*   Updated: 2025/02/15 14:20:46 by ekibar         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    write_message(int signal_type)
{
        static int      i;
        static char     a;

        a = a << 1;
        if (signal_type == SIGUSR1)
                a = a | 1;
        else if (signal_type == SIGUSR2)
                a = a | 0;
        else
                return;
        if (i == 7)
                ft_printf("%c", a);
        i++;
        if (i == 8)
        {
                a = 0;
                i = 0;
        }
}

int     main()
{
        int     server_pid;

        server_pid = getpid();
        if (server_pid <= 0)
        {
                ft_printf("Error: PID alınamadı!\n");
                return (1);
        }
        ft_printf("Server PID: %d\n", server_pid);
        if (signal(SIGUSR1, write_message) == SIG_ERR)
        {
                ft_printf("Error: SIGUSR1 sinyali ayarlanamadı!\n");
                return (1);
        }
        if (signal(SIGUSR2, write_message) == SIG_ERR)
        {
                ft_printf("Error: SIGUSR2 sinyali ayarlanamadı!\n");
                return (1);
        }
        while(1)
                pause();
}
