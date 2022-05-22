#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    //key for initialization of shared memory
    key_t key = ftok("jsk", 100);
    
    //create shared memory
    int shmid = shmget(key, 1024, 0666| IPC_CREAT);
    printf("shared memory id = %d\n", shmid);
    //attach shared memory to str
    char* str = (char*)shmat(shmid, (void*)0, 0);

    //placing data in shared memory
    gets(str);

    //detach from shared memory
    shmdt(str);

    return 0;

}