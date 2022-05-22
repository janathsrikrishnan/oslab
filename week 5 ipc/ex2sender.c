#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 1000

struct mess_buf{
    long mesg_type;
    char mesg_text[1000];
} message;

int main()
{
    key_t key;
    int msgid;

    key = ftok("jsk", 100);
    printf("key = %d\n", key);
    
    //create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    printf("message queue id = %d\n", msgid);
    message.mesg_type = 1;

    // get data from user
    printf("write Data: ");
    fgets(message.mesg_text, MAX, stdin);

    // send the data 
    msgsnd(msgid, &message, sizeof(message), 0);

    // display the message
    printf("Data to send is :%s\n", message.mesg_text);
    
    return 0;
}