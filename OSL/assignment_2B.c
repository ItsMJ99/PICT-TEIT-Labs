#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/type.h>

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
        _exit(1);
    }
    else if(){
        printf("Process started with pid : %d\n", getpid());
        bubbleSort(arr,n);
        printf("Sorted array : ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        char *args[n+2];
        arg[0]="./cp";
        exec(args[0],args,NULL);
        return 1;
    }
    else{
        wait(NULL);
        printf("Parent Process Completed!!!\n");
    }
    return 0;
}