#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void binarySearch(int arr[],int n){
    int key;
    printf("--------------- Binary Search --------------");
    printf("\n\nEnter the element to search : ");
    scanf("%d",&key);
    int b=0,e=n-1;
    while(b<=e){
        int m=(b+e)/2;
        if(key==arr[m]){
            printf("\nElement %d found at index %d",key,m);
            break;
        }
        else if(key>arr[m]){
            b=m+1;
        }
        else {
            e=m-1;
        }
    }
    if(b>e){
        printf("\nElement %d not found !!!\n",key);
    }    
}

int main(int argc,char *argv[],char *envp[]){
    int n=0;
    int arr[10];
    for(int i=1;argv[i]!=NULL;i++){
        arr[i]=strtol(argv[i],NULL,10);
        n++;
    }
    printf("Current PID : %d.\n",getpid());
    printf("Parent PPID : %d.\n",getppid());
    binarySearch(arr,n);
    printf("\nBinary Search Completed!!!\n");
    return 0;
}