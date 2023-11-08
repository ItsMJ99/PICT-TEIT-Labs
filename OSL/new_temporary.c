#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

void bubbleSort(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i]<arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

int main(){
	char *argv[12];
	int n,i;
	for(i=0;i<12;i++){
		argv[i]=(char *)malloc(20);
	}
	printf("In Main program : (PID : %d)\n",getpid());
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	bubbleSort(arr,n);
	printf("\nSorted Array : ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	pid_t pid=fork();
	if(pid<0){
		printf("\nFork Failed !!!\n");
		exit(1);
	}
	else if(pid==0){
		printf("\nChild Process (PID : %d).\n",getpid());
		printf("Child Process Parent ID (PPID : %d).\n",getppid());
		printf("Child Process calls binary search program using execv....\n");
		for(i=0;i<n;i++){
			sprintf(argv[i+1],"%d",arr[i]);
		}
		argv[0]="./ex2";
		argv[n+2]=NULL;
		execv("./ex2",argv);
		printf("Error\n");
		printf("Child Process is terminating\n");
		printf("-----------------------------------------------------------------\n\n");
	}
	else{
		wait(NULL);
		printf("\nParent Process is terminating.\n");
		printf("-----------------------------------------------------------------\n\n");
	}
	return 0;
}