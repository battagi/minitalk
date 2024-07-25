#include"minitalk.h"
void char_handler(int sig, siginfo_t *info)
{

    static char c = 0;
    static int i = 0;
    static int main_pid = 0;

    if(!main_pid)
        main_pid = info->si_pid;
    if(info->si_pid != main_pid)
    {
        // printf("hello\n");
        main_pid =info->si_pid;
        i = 0;
    }
    if (sig == 1)
    {
       c =  c | (1 << i);
    }
    i++;
    if (i == 8)
    {
        i = 0;
        write(1, &c, 1);
        c = 0;
    }
    
}

void handler(int signum, siginfo_t *info, void *ptr)
{

    if (signum == SIGUSR1) 
    {
        char_handler(1,info);
    }
    else if (signum == SIGUSR2)  
    {
        char_handler(0, info);
    }
}

int main(void)
{
    struct sigaction sa;
    int pid;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &handler;
    pid = getpid();
    printf("PID: %d\n", pid);  

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
    {
        // pause();  
        //
    }

    return 0;
}
