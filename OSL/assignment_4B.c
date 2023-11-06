#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex;
sem_t wrt;
int readcount=0,nwt,nrd;

void *reader_thread(void *temp){
	int *id_ptr=(int *)temp;
	int id=*id_ptr;
	free(id_ptr);
	printf("Reader %d is trying to enter the Database for reading\n",id);
	sem_wait(&mutex);
	readcount++;
	if(readcount==1)
		sem_wait(&wrt);
	sem_post(&mutex);

	printf("Reader %d is reading from the database\n",id);
	sem_wait(&mutex);
	readcount--;
	if(readcount==0)
		sem_post(&wrt);
	sem_post(&mutex);
	printf("Reader %d left the Database\n",id);
	sleep(5);
	pthread_exit(NULL);
}

void *writer_thread(void *temp){
	int *id_ptr=(int *)temp;
	int id=*id_ptr;
	free(id_ptr);
	printf("Writer %d is trying to enter the Database for writing\n",id);
	sem_wait(&wrt);
	printf("Writer %d is now writing in the Database\n",id);
	sleep(5);
	printf("Writer %d left the Database\n",id);
	sem_post(&wrt);
	pthread_exit(NULL);
}

int main(){
	long int i;
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	pthread_t reader[100],writer[100];
	printf("\nEnter the number of Writers : ");
	scanf("%d",&nwt);
	printf("\nEnter the number of Readers : ");
	scanf("%d",&nrd);
	for(i=1;i<=nwt;i++){
		int *writer_id=malloc(sizeof(int));
		*writer_id=i;
		pthread_create(&writer[i],NULL,writer_thread,(void *)writer_id);
	}
	for(i=1;i<=nrd;i++){
		int *reader_id=malloc(sizeof(int));
		*reader_id=i;
		pthread_create(&reader[i],NULL,reader_thread,(void *)reader_id);
	}
	for(i=1;i<=nwt;i++){
		pthread_join(writer[i],NULL);
	}
	for(i=1;i<=nrd;i++){
		pthread_join(reader[i],NULL);
	}
	sem_destroy(&wrt);
	sem_destroy(&mutex);
	pthread_exit(NULL); // Exit the main thread gracefully
	return 0;
}