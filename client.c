#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		usleep(100);
		i++;
	}
}
int	ft_is_degit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc == 3)
	{
		i = 0;
		pid = atoi(argv[1]);
		while (argv[1][i])
		{
			if (!ft_is_degit(argv[1][i]) || pid < 0)
			{
				printf("invalid pid !\n");
				return (1);
			}
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			ft_send_char(pid, argv[2][i]);
			i++;
		}
	}
	else
		printf("must provide additional or fewer arguments !\n");
}
