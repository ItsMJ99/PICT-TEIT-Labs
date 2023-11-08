#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>

int main(){
    int i;
    char buff[100];
    void *shared_memory;
    int shmid;
    shmid=shmget((key_t)1001,1024,0666);
    printf("Shared Memory Key : %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("Process attached at : %p\n",shared_memory);
    printf("Data read from shared memory : %s\n",(char *)shared_memory);
    shmdt(shared_memory);
    return 0;
}