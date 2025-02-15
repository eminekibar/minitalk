#include "minitalk.h"

void    send_message(char a, int server_PID)
{
    int i;

    i = 0;
    while(i < 8)
    {
        if((a << i) & 128)
            kill(server_PID, SIGUSR1);
        else
            kill(server_PID, SIGUSR2);
        i++;
        usleep(100);
    }
}

int main(int argc, char *argv[])
{
    int server_PID;
    int i;

    i = 0;
    if(argc == 3)
    {
        server_PID = ft_atoi(argv[1]);
        while(argv[2][i])
        {
            send_message(argv[2][i], server_PID);
            i++;
        }
    }
}
