#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void main (void)
{
	pid_t pid;
	pid = fork();

	switch (pid)
	{
		case 0:
			system("./printf_helloworld");
			break;
		case -1:
			printf("ERROR.!!!\n");
			break;
		default:
			execlp("./printf_xinchao","/media/nhanmt/0647acb4-1da4-40de-81a5-71c2e7b3db9f/04.PRACTICE-LINUX/printf_xinchao",0);
			break;
	}
}
