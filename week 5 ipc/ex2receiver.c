#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>


// message type shoude be long otherwise it doesn't work

struct mess_buf{
    long mesg_type;
    char mesg_text[1000];
} message;

int main()
{
    printf("receiving message from message queue id: ");
    key_t key;
    int msgid;

    key = ftok("jsk", 100);

    // getting message id
    msgid = msgget(key, 0666 | IPC_CREAT);
    printf("%d\n", msgid);

    //RECEIVE
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    //display
    printf("Data Received is : %s\n", message.mesg_text);

    // terminate message queue from memory
    msgctl(msgid, IPC_RMID, NULL);
    return 0;

}