#include "minitalk.h"

void    send_message(char a, int server_pid)
{
    int i;

    i = 0;
    while(i < 8)
    {
        if((a << i) & 128)
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
    
        i++;
        usleep(100);
    }
}

int main(int argc, char *argv[])
{
    int server_pid;
    int i;

    i = 0;
    if(argc == 3)
    {
        server_pid = ft_atoi(argv[1]);
        if (server_pid != true_pid())
        {
            ft_printf("Hata: Geçersiz PID!\n");
            return (1);
        }
        while(argv[2][i])
        {
            send_message(argv[2][i], server_pid);
            i++;
        }
    }
    else
    {
        ft_printf("Error: %s <Server_PID> <Message>\n", argv[0]);
        exit (0);
    }
}
