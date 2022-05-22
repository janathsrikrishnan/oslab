#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t semEmpty;
sem_t semFull;
sem_t mutex;

int buffer[50];
int count = 0;

void* producer(void* argv)
{   
    while(1)
    {
        int x  = rand() % 100;
        int EmpytVal, FullVal;

        // put into sleep to see the working of semaphore
        

        // getting lock to write into the buffer
        sem_wait(&semEmpty);
        sem_wait(&mutex);
        sleep(1);
        // getting current value of semaphore
        sem_getvalue(&semEmpty, &EmpytVal);
        sem_getvalue(&semFull, &FullVal);

        //writting in the buffer
        buffer[count] = x;
        count++;
        
        printf("Semaphore Empty value: %d Full value: %d writing %d into buffer\n", EmpytVal, FullVal, x);

        sem_post(&mutex);
        sem_post(&semFull);
    }
}

void* consumer(void* argv)
{
    while(1)
    {
        int EmptyVal, FullVal, y;
        sem_wait(&semFull);
        sem_wait(&mutex);

        sem_getvalue(&semFull, &FullVal);
        sem_getvalue(&semEmpty, &EmptyVal);

        // reading from buffer
        y = buffer[count-1];
        count--;

        printf("semaphore Empty: %d Full: %d read %d from buffer\n", EmptyVal, FullVal, y);
        
        // releasing semaphore
        sem_post(&mutex);
        sem_post(&semEmpty);
    }
}

int main()
{
    srand(time(NULL));

    // initialize semaphore value
    sem_init(&mutex, 0, 1);
    sem_init(&semEmpty, 0, 10);
    sem_init(&semFull, 0, 0);

    pthread_t thread[2];

    pthread_create(&thread[0], NULL, producer, NULL);
    pthread_create(&thread[1], NULL, consumer, NULL);

    for(int i = 0; i < 2; i++) {pthread_join(thread[i], NULL);}
    //destroying semaphore
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    sem_destroy(&mutex);

}