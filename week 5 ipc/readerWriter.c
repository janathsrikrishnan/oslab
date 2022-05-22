#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFFER_SIZE 20

sem_t semWrite; // counting semaphore

sem_t mutex;    // binary semaphore

int read_count = 0;

int buffer[BUFFER_SIZE] = {3, 4, 5, 3, 2, 3, 5, 90, 80, 30,
                  22, 66, 874, 434, 43, 5, 1000, 32, 100};

void* reader(void* argv)
{
    while(1)
    {
        sem_wait(&mutex);
        read_count++;

        if(read_count == 1)
        {
            sem_wait(&semWrite);
        }
        sem_post(&mutex);

        int x = rand() % BUFFER_SIZE;
        int y = buffer[x];
        printf("%d read from buffer at %d\n", y, x);
        sem_wait(&mutex);
        read_count--;
        if (read_count == 0) sem_post(&semWrite);
        sem_post(&mutex);
        sleep(1);
    }
}

void* writer(void* argv)
{
    while(1)
    {
        int x = rand() % 1000;
        int y = rand()%BUFFER_SIZE;
        
        sem_wait(&semWrite);
        buffer[y] = x;
        printf("%d write into buffer at %d\n", x, y);
        sem_post(&semWrite);
        sleep(1);
    }
}


int main()
{
    pthread_t thread[2];

    //initialize
    sem_init(&semWrite, 0, 1);
    sem_init(&mutex, 0, 1);

    pthread_create(&thread[0], NULL, reader, NULL);
    pthread_create(&thread[1], NULL, writer, NULL);

    for (int i = 0; i < 2; i++) pthread_join(thread[i], NULL);

    sem_destroy(&semWrite);
    sem_destroy(&mutex);
}