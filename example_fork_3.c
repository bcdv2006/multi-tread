#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void catch_child(void);
void main (void)
{
	pid_t pid;
	pid = fork();
	char i = 0;
	char j = 0;
	int child_status;

    signal(SIGCHLD,catch_child);
	switch (pid)
	{
		case -1:
			printf("khong the tao tien trinh moi\n");
			exit(0);
		case 0:
			for(i = 0; i < 10; i++)
			{
				printf("tien trinh CON dang chay duoc %d lan\n",i);
				sleep(1);
			}
			exit(37); // mã lỗi trả về của tiến trình con
		default:
			for(j = 0;j < 3;j++)
			{
				printf("tien trinh CHA dang chay duoc %d lan\n",j);
				sleep(1);
			}

			if(WIFEXITED(child_status))
			{
				printf("chuong trinh CON thoat ra ma %d\n", WEXITSTATUS(child_status));
			}
			else
			{
				printf("chuong trinh CON thoat binh thuong\n");
			}
			break;
	}
	exit(0);
}


void catch_child(void)
{
    printf("tien trinh CHA - tien trinh con da chay xong\n");
}