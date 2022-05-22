#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key = ftok("jsk", 100);

    // opening sharedd memory
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);

    // attach to shared memory
    char* str = (char*)shmat(shmid, (void*)0,0);

    printf("Reading from shared memory id : %d\n", shmid);
    printf("reading data : %s\n", str);

    shmctl(shmid, IPC_RMID, NULL);
}