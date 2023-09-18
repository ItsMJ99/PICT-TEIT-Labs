#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

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

int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    pid_t pid=fork();
    if(pid<0){
        printf("FORK was Unsuccessful!!!\n");
        exit(1);
    }
    else if(pid==0){
        printf("Process Started with PID : %d",getpid());
        bubbleSort(arr,n);
        printf("\nSorted Array : ");
        for(int i=0;i<n;i++){
            printf("\t%d",arr[i]);
        }
        char *args[] = { "./assignment_2B_2.c", "12", "34", "23", NULL };
        execve(args[0], args, NULL);
        perror("Execve Failed");
        exit(1);
    }
    else{
        int status;
        wait(&status);
        printf("\nParent Process Completed!!!\n");
    }
    return 0;
}