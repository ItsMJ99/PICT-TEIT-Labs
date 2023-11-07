#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

void fifo(){
    int f;
    char s[100];
    printf("Enter the Pages string : ");
    scanf("%s",s);
    printf("Enter the number of Frames : ");
    scanf("%d",&f);
    int pageHits=0;
    int pageFaults=0;
    int cf=0;
    char frames[f];
     printf("\n\t");
    for(int i=0;i<f;i++){
        printf("\tF%d",i+1);
    }
    printf("\n");
    for(int i=0;i<strlen(s);i++){
        bool found=false;
        for(int j=0;j<f;j++){
            if(frames[j]==s[i]){
                found=true;
                pageHits++;
                break;
            }
        }
        if(!found){
            frames[cf]=s[i];
            pageFaults++;
        }
        printf("Page %c :\t",s[i] );
        for(int i=0;i<f;i++){
            printf("%c\t",frames[i]);
        }
        if(found){
            printf("Hit\n");
        } 
        else{
            printf("Fault\n");
            cf=(cf+1)%f;
        }
    }
    printf("\n\nTotal Number of Page Hits : %d",pageHits);
    printf("\nTotal Number of Page Faults : %d\n\n",pageFaults);
}

void optimal(){
    int f;
    char s[100];
    printf("Enter the Pages string : ");
    scanf("%s",s);
    printf("Enter the number of Frames : ");
    scanf("%d",&f);
    char frames[f];
    int pageHits=0;
    int pageFaults=0;

    printf("\n\t");
    for(int i=0;i<f;i++){
        printf("F%d\t",i+1);
    }
    printf("\n");
    for (int i = 0; i < f; i++) {
        frames[i] = '\0'; // Initialize frames to NULL character
    }
    for(int i=0;i<strlen(s);i++){
        bool found=false;
        for(int j=0;j<f;j++){
            if(frames[j]==s[i]){
                pageHits++;
                found=true;
                break;
            }
        }
        if (!found) {
            if (pageFaults < f) {
                frames[pageFaults] = s[i];
            } else {
                int ind[f];
                for (int m = 0; m < f; m++) {
                    ind[m] = -1;
                    for (int n = i + 1; n < strlen(s); n++) {
                        if (frames[m] == s[n]) {
                            ind[m] = n;
                            break;
                        }
                    }
                }
                int im = 0;
                for (int x = 0; x < f; x++) {
                    if (ind[x] == -1 || (ind[im] != -1 && ind[x] > ind[im])) {
                        im = x;
                    }
                }
                frames[im] = s[i];
            }
        pageFaults++;
        }


        printf("Page %c : ",s[i]);
        for(int k=0;k<f;k++){
             if (frames[k] != '\0') {
                printf("%c\t", frames[k]);
            } else {
                printf(" \t"); // Empty frame
            }
        }
        if(found){
            printf("Hit\n");
        }
        else{
            printf("Fault\n");
        }
    }
    printf("\n\nTotal Number of Page Hits : %d",pageHits);
    printf("\nTotal Number of Page Faults : %d\n\n",pageFaults);
}

void lru() {
    int f;
    char s[100];
    printf("Enter the Pages string: ");
    scanf("%s", s);
    printf("Enter the number of Frames: ");
    scanf("%d", &f);
    char frames[f];
    int pageHits = 0;
    int pageFaults = 0;
    int age[f]; // Array to keep track of age for each frame

    printf("\n\t");
    for (int i = 0; i < f; i++) {
        printf("F%d\t", i + 1);
        age[i] = 0;
    }
    printf("\n");

    for (int i = 0; i < f; i++) {
        frames[i] = '\0'; // Initialize frames to NULL character
    }

    for (int i = 0; i < strlen(s); i++) {
        bool found = false;
        for (int j = 0; j < f; j++) {
            if (frames[j] == s[i]) {
                pageHits++;
                found = true;
                // Update the age of the frame
                age[j] = 0;
                // Increment age for other frames
                for (int k = 0; k < f; k++) {
                    if (k != j) {
                        age[k]++;
                    }
                }
            } else {
                // Increment the age for frames that are not hit
                age[j]++;
            }
        }
        if (!found) {
            if (pageFaults < f) {
                frames[pageFaults] = s[i];
                age[pageFaults] = 0;
            } else {
                int max_age = age[0];
                int max_age_index = 0;
                // Find the frame with the maximum age
                for (int k = 1; k < f; k++) {
                    if (age[k] > max_age) {
                        max_age = age[k];
                        max_age_index = k;
                    }
                }
                frames[max_age_index] = s[i];
                age[max_age_index] = 0;
            }
            pageFaults++;
        }

        printf("Page %c : ", s[i]);
        for (int k = 0; k < f; k++) {
            if (frames[k] != '\0') {
                printf("%c\t", frames[k]);
            } else {
                printf(" \t"); // Empty frame
            }
        }
        if (found) {
            printf("Hit\n");
        } else {
            printf("Fault\n");
        }
    }

    printf("\n\nTotal Number of Page Hits: %d", pageHits);
    printf("\nTotal Number of Page Faults: %d\n\n", pageFaults);
}

int main(){
    int c=0,ch;
    while(c==0){
        printf("==========Menu==========");
        printf("\n0.Exit\n1.FIFO / FCFS\n2.Optimal\n3.LRU\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                c=1;
                break;
            case 1:
                fifo();
                break;
            case 2:
                optimal();
                break;
            case 3:
                lru();
                break;
            default:
                printf("Invalid Input !!! ");
        }
    }
    return 0;
}
 