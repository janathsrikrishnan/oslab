#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

sem_t semCustomer;
sem_t semBarber;
sem_t seat;

int freeSeat;

void* Barber(void* argv)
{
    while(1)
    {
        sem_wait(&semCustomer);
        sem_wait(&seat);

        freeSeat++;
        printf("Barber: No of chairs are free is %d\n", freeSeat);
        sem_post(&semBarber);
        sem_post(&seat);
        sleep(1);
    }
}

void* Customer(void* argv)
{
    while(1)
    {
        sem_wait(&seat);

        if (freeSeat > 0)
        {
            freeSeat--;
            printf("Customer: No of chairs are free is %d\n", freeSeat);
            sem_post(&semCustomer);
            sem_post(&seat);
            sem_wait(&semBarber);
        }
        else sem_post(&seat);
        //printf("Customer: No of chairs are free is %d\n", freeSeat);
        sleep(rand()%5);
    }
}

int main()
{
    srand(time(NULL));
    pthread_t thread[3];
    int n;
    printf("Enter no of chair avaialbe: ");
    scanf("%d", &n);
    freeSeat = n;
    //initialize
    sem_init(&semCustomer, 0, 0);
    sem_init(&seat, 0, 1);
    sem_init(&semBarber, 0, 1);
    
    pthread_create(&thread[0], NULL, Customer, NULL);
    pthread_create(&thread[1], NULL, Barber, NULL);
    pthread_create(&thread[2], NULL, Customer, NULL);
    for (int i =0; i < 3; i++) pthread_join(thread[i], NULL);

    sem_destroy(&seat);
    sem_destroy(&semCustomer);
    sem_destroy(&semBarber);
}