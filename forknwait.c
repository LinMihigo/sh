#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
/**
* main - fork, wait and exec
* Return: 0
*/
int main(void)
{
	pid_t c_pid;
	int status, i = 0;
    const char *path = "/bin/ls";
	char *const argv[] = { "ls", "-l", "/tmp", NULL};
	char *const envp[] = { "HOME=/home/lin", "PATH=/usr/bin" };

	/* path is command path
	*  argv is the parsed command we need to execute. E.g ls -al /home/lin
	*  envp is the system environemtn path. (Not sure why we need the system env path)
	*/
	
	while (i < 5)
	{
		c_pid = fork();
		if (c_pid == -1)
		{
			perror("Error: forking");
			return (1);
		}
		if (c_pid == 0)
		{
			printf("PPID: %u\n", getppid());
			printf("PID: %u\n", getpid());
			if (execve(path, argv, envp) == -1)
				perror("Error: execve");
		}
		else
		{
			wait(&status);
			printf("\n");
			i++;
		}
	}
}
