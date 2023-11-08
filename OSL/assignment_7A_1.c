#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd;
    char *myfifo1="/tmp/myfifo1";
    char *myfifo2="/tmp/myfifo2";
    mkfifo(myfifo1,0666);
    mkfifo(myfifo2,0666);
    char arr1[100],arr2[100];
    while(1){
        fd=open(myfifo1,O_WRONLY);
        printf("You : ");
        fgets(arr2,100,stdin);
        write(fd,arr2,strlen(arr2)+1);
        close(fd);
        fd=open(myfifo2,O_RDONLY);
        read(fd,arr1,sizeof(arr1));
        printf("User 2 : %s\n",arr1);
        close(fd);
        FILE *outputfile=fopen("output.txt","w");
        int wordCount=0,charCount=0,lineCount=0;
        for(int i=0;arr1[i]!='\0';i++){
            if(arr1[i]==' '||arr1[i]=='\n'){
                wordCount++;
            }
            if(arr1[i]!=' '){
                charCount++;
            }
            if(arr1[i]=='\n'){
                lineCount++;
            }
        }
        fprintf(outputfile,"Charcount = %d\nWord Count = %d\nLine Count = %d",charCount-1,wordCount,lineCount);
        fclose(outputfile);
    }
    return 0;
}
