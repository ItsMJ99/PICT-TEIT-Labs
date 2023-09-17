#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <stdlib.h>

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }       
        }
    }
}

bool linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
            break;
        }
    }
    return false;
}

int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    bubbleSort(arr,n);
    int ch,con=0;
    //while(con==0){
        printf("==========Menu==========");
        printf("\n0. Exit\n1. fork, wait, Bubble Sort\n2. Zombie Process\n3. Orphan Proces\n");
        printf("Enter Choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:{
                con=1;
                break;
            }
            case 1:{
                int key;
                printf("Enter Key to Search : ");
                scanf("%d",&key);
                pid_t pid=fork();
                if(pid<0){
                    printf("FORK was Unsuccessful!!!\n");
                    _exit(1);
                }
                else if(pid==0){
                    printf("Child Process Bubble Sort is Running\n");
                    printf("After Child Process Bubble Sort is Running Completed\n");
                    for(int i=0;i<n;i++)
                        printf("\t%d",arr[i]);
                    printf("\n");
                }
                else{
                    printf("Parent Process Linear Search is Running\n");
                    if(linearSearch(arr,n,key))
                        printf("%d Key Found\n",key);
                    else
                        printf("%d Key Not Found\n",key);
                    wait(NULL);
                    printf("Child process has completed.\n");
                }
                break;
            }
            case 2:{//Zombie process = process who is terminated before parent process calls wait() to get return status
                pid_t pid=fork();
                if(pid<0){
                    printf("FORK was Unsuccessful!!!\n");
                    _exit(1);
                }
                else if(pid==0){
                    printf("\n(Zombie)Child process started with PID : %d.\n",getpid());
                    printf("Child process with PID: %d completed.\n", getpid());
                }
                else{
                    sleep(10);
                    char command[100];
                    sprintf(command, "ps -elf | grep %d", getpid());
                    system(command);
                    printf("\n(Zombie)Parent process started with PID : %d\n",getppid());
                    printf("Parent process wiht PID : %d completed.\n", getppid());
                    wait(NULL);
                }
                break;
            }
            case 3:{//Orphan Process = process whos parents are killed or terminated
                pid_t pid=fork();
                if(pid<0){
                    printf("\nFORK was Unsuccessful!!!\n");
                    _exit(1);
                }
                else if(pid==0){
                    printf("\nOrphan Process Started with PID : %d",getpid());
                    printf("\nParent Process PID : %d",getppid());
                    sleep(10);//this will create orphan process
                    printf("\nOrphan Process Completed with PID : %d",getpid());
                }
                else
                {
                    printf("\nParent process started with PID : %d\n", getppid());
                    sleep(5);
                    system("ps -elf | grep -e 'PPID\\|CHILD'");
                    printf("Parent process with PID %d completed.\n", getppid());
                }
                break;
            }
            default:{
                printf("Invalid Input !!!");
                break;
            }
        }
    //}
    return 0;
}