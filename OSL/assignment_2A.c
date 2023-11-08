#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void bubbleSort(int arr[],int n){
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]<arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

int merge(int arr[],int l,int r){
	int p=arr[l];
	int beg=l;
	l+=1;
	int temp;
	while(l<=r){
		if(p<=arr[l] && arr[r]>=p){
			temp=arr[l];
			arr[l]=arr[r];
			arr[r]=temp;
			l++;
			r--;
		}
		if(p>arr[l]){
			l++;
		}
		if(p<arr[r]){
			r--;
		}
	}
	temp=arr[beg];
	arr[beg]=arr[r];
	arr[r]=temp;
	return r;
}

void mergeSort(int arr[],int l,int r){
	if(l<r){
		int m=merge(arr,l,r);
		mergeSort(arr,l,m-1);
		mergeSort(arr,m+1,r);
	}
}

int main(){
	int n,i;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements : ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int c=0,ch;
	//while(c==0){
		printf("\n========== MENU ==========\n");
		printf("\n0.Exit\n1. Fork, Wait, Merge and Bubble Sort\n2. Orphan Process\n3. Zombie Process : ");
		printf("\n\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 0:
				c=1;
				break;
			case 1:
				pid_t pid=fork();
				if(pid<0){
					printf("\nForking Failed !!!\n");
					exit(1);
				}
				else if(pid == 0){
					printf("\nChild Process is performing Bubble Sort\n");
					bubbleSort(arr,n);
					printf("\nArry Sorted by Child Process using bubble sort\n");
					for(i=0;i<n;i++){
						printf("%d ",arr[i]);
					}
					printf("\n");
				}
				else{
					printf("\nParent Process is performing Merge Sort\n");
					mergeSort(arr,0,n-1);
					printf("\nArray Sorted by Paret Process using Merge Sort\n");
					for(i=0;i<n;i++){
						printf("%d ",arr[i]);
					}
					printf("\n");
					wait(NULL);
					printf("\nChild Process Completed its Execution\n");
				}
				break;
			case 2:{
				pid_t pid=fork();
				if(fork<0){
					printf("Forking Failed !!!\n");
					exit(1);
				}
				else if(pid==0){
					// Orphan process
					printf("\nOrphan Process started (PID:%d).\n",getpid());
					printf("\nParent Process (PID:%d) terminated before child Process.\n",getppid());
					// Sleep to create an orphan process
                	sleep(10);
					printf("\nOrphan Process (PID:%d) completed.\n",getpid());
				}
				else{
					//Parent Process
					printf("\nParent Process (PID:%d) started\n",getppid());
					sleep(5);
					char command[100];
					sprintf(command,"ps -elf | grep %d.",getpid());
					system(command);
					printf("\nParent Process (PID:%d) Completed\n",getppid());
				}
				break;
			}
			case 3:{
				pid_t pid=fork();
				if(pid<0){
					printf("Fork Failed !!!");
					exit(1);
				}
				else if(pid == 0){
					printf("Child Process Started (PID : %d).",getpid());
					printf("Child Process Completed (PID : %d) it is now a Zombie Process.",getpid());
				}
				else{
					sleep(5);
					char command[100];
					sprintf(command,"ps -elf | grep %d.",getpid());
					system(command);
					printf("\nParent Process Started : (PID:%d) : \n",getppid());
					printf("Parent Process will now sleep : (PID:%d) : \n",getppid());
					printf("\nParent Process Completed : (PID:%d) : \n",getppid());
					wait(NULL);
				}
				break;
			}
			default:
				printf("Invalid Input !!!");
		}
	//}
	return 0;
}