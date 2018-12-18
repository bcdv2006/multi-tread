#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMBER_THREAD   6
/*0: chay tu 1 den 6
  1: chay tu 6 den 1*/
#define FROM6TO1        1
#define TIME_WAIL       5
void* do_loop(void* data)
{
    int *me = (int*)data;
    for(int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("tien trinh <%d> - chay duoc %d%%\n", *me, (i+1)*20);
    }
    printf("tien trinh %d da chay xong\n",*me);
    pthread_exit("Dong nay se duoc luu vao bien: <thread_return>");
}


int main(int argc, char* argv[])
{
    int resp;
    pthread_t thread[NUMBER_THREAD];
    void* thread_return;
#if FROM6TO1
    printf("CHAY O CHE DO %d TU 6-1\n", FROM6TO1);
#else
    printf("CHAY O CHE DO %d TU 1-6\n", FROM6TO1);
#endif
    for(int num_thread = 0; num_thread < NUMBER_THREAD; num_thread++)
    {
        resp = pthread_create(&thread[num_thread], NULL, &do_loop, (void*)&num_thread);

        if(resp != 0)
        {
            perror("thread create error\n");
            //exit(ERROR_FAILURE);
        }
        sleep(TIME_WAIL);
    }
    printf("cho tao thread xong \n");
    #if FROM6TO1
    for( int num_thread = NUMBER_THREAD -1; num_thread < 0; num_thread--)
    #else
    for( int num_thread = 0; num_thread < NUMBER_THREAD; num_thread++)
    #endif
    {
        resp = pthread_join(thread[num_thread], &thread_return);
        if(resp != 0)
        {
            perror("thread create error\n");
            //exit(ERROR_FAILURE);
        }
        else
        {
            printf("pick up %d thread\n", num_thread);
        }
        sleep(TIME_WAIL);
    }
    printf("tat ca cac thread da pass\n"); 
    return 0;
}
/**********************************************************************
*                                                                     *                                                                     
*           gcc thread_create.c -o thread_create -lpthread            *
*     cần thêm option '-lpthread' vào khi biên dịch chương trình      *
*                                                                     *          
***********************************************************************/