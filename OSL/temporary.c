#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>

int main(){
    int i;
    char buff[100];
    void *shared_memory;
    int shmid;
    shmid=shmget((key_t)1001,1024,0666 | IPC_CREAT);
    printf("Shared Memory Key : %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("Process Attached to shared memory at %p\n",shared_memory);
    printf("Enter data to enter in shared memory : ");
    fgets(buff,sizeof(buff),stdin);
    strncpy(shared_memory,buff,100);
    shmdt(shared_memory);
    return 0;
}