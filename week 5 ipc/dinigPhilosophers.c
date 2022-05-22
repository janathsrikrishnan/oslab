#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define PHILOSOPHERS 5

sem_t chopstick[PHILOSOPHERS];

void* eating(void* argv)
{
    while(1)
    {
        int i = rand() % PHILOSOPHERS;
        
        sem_wait(&chopstick[i]);
        sem_wait(&chopstick[(i+1) % PHILOSOPHERS]);

        printf("PHILOSOPHERS %d is eating\n", i);

        sem_post(&chopstick[i]);
        sem_post(&chopstick[(i+1) % PHILOSOPHERS]);

        printf("PHILOSOPHERS %d is now thinking\n", i);
        sleep(1);
    }
}

int main()
{
    pthread_t thread[2];

    srand(time(NULL));

    for (int i = 0; i < PHILOSOPHERS; i++) 
        sem_init(&chopstick[i], 0, 1);

    pthread_create(&thread[0], NULL, eating, NULL);

    pthread_join(thread[0], NULL);
}
