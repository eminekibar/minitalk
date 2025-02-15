#include "minitalk.h"

void write_message(int signal_type)
{
    static int i;
    static char a;

    if(signal_type == SIGUSR1)
        a = (a << 1) | 1;
    else if(signal_type == SIGUSR2)
        a = (a << 1);
    i++;
    if(i == 8)
    {
        ft_printf("%c", a);
        i = 0;
        a = 0;
    }
}

int main()
{
    ft_printf("Server PID: %d\n", getpid());
    signal(SIGUSR1, write_message);
    signal(SIGUSR2, write_message);
    while(1)
        pause();
}
