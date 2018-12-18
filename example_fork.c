#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void main (void)
{
	pid_t pid;
	pid = fork();
    char i = 0;
	switch (pid)
	{
		case 0:
			for(i = 0; i<10; i++)
            {
                printf("Cha.!!! %d\n", i);
            }
            exit(0);
			break;
		case -1:
			printf("ERROR.!!!\n");
			break;
		default:
			for(i = 0; i<10; i++)
            {
                printf("Con.!!! %d\n", i);
            }
            exit(0);
			break;
	}
}
