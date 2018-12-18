#include <stdio.h>
#include <unistd.h>

void main (void)
{
	printf("excute ls command with execlp.\n");
	execlp("ls","ls",0);
	printf("Done...!!!!\n");
}
