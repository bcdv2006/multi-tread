#include <stdio.h>
#include <pthread.h>


void* do_loop(void* data)
{
    int *me = (int*)data;
    for(int i = 0; i < 5; i++)
    {
        sleep(1);
        printf("'%d' - Got '%d'\n", *me, i);
    }
    pthread_exit("Dong nay se duoc luu vao bien: <thread_return>");
}

void* do_loop_2()
{
    for(int i =0; i < 5; i++)
    {
        sleep(1);
        printf("dem ngay xa em <%d>\n",i);
    }
    printf("bye.!\n");
    pthread_exit("Ket Thuc Thread\n");
}

int main(int argc, char* argv[])
{
    int thr_a_id, thr_b_id;
    pthread_t a_thread, b_thread;
    int a = 1;
    int b = 2;
    void *thread_return;
    printf("bat dau thread_a\n");
    /* tạo một tiến trình mới có ID được lưu vào th_a_ID*/
    thr_a_id = pthread_create(&a_thread, NULL, &do_loop, (void*)&a);

    /*hàm này chờ a_thread chạy xong. và chuyền kết quả ở hàm thread_exit về
    biến thread_return*/
    pthread_join(a_thread, &thread_return);

    printf("result: %s: \n",(char*)thread_return);

    printf("ket thuc thread_a\n");
    /* tạo một tiến trình mới có ID được luư vào biến thr_b_ip*/
    thr_b_id = pthread_create(&b_thread, NULL, &do_loop_2, NULL);

    /*Tiến trình chính bất đầù chạy */
    do_loop((void*)&b);
    return 0;
}
/**********************************************************************
*                                                                     *                                                                     
*           gcc thread_create.c -o thread_create -lpthread            *
*     cần thêm option '-lpthread' vào khi biên dịch chương trình      *
*                                                                     *          
***********************************************************************/