#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock;
int counter = 0;

void *thread_func(void *arg)
{
    pthread_mutex_lock(&lock);  // 🔒 뮤텍스 잠금
    counter++;
    printf("Thread %ld: counter = %d\n", (long)arg, counter);
    pthread_mutex_unlock(&lock);  // 🔓 뮤텍스 해제
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);  // 뮤텍스 초기화

    pthread_create(&t1, NULL, thread_func, (void *)1);
    pthread_create(&t2, NULL, thread_func, (void *)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);  // 뮤텍스 제거
    return 0;
}
