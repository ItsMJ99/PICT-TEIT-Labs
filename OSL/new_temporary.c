 #include<stdio.h>
#include<stdbool.h>

struct Process{
    int pid;
    int allocated[3];
    int maxneed[3];
    int remneed[3];
    bool cs;
};

void showTable(struct Process p[],int n){
     printf("PID\tAllocated\tMax Need\tRemaining Need\n");
    printf("\tA  B  C         A  B  C         A  B  C\n");
    for(int i=0;i<n;i++){
        printf(" %d\t",i+1);
        for(int j=0;j<3;j++){
            printf("%d  ",p[i].allocated[j]);
        }
        printf("\t");
        for(int k=0;k<3;k++){
            printf("%d  ",p[i].maxneed[k]);
        }
        printf("\t");
        for(int l=0;l<3;l++){
            printf("%d  ",p[i].remneed[l]);
        }
        printf("\n");
    } 
}

void safetyAlgorithm(struct Process p[],int n,int taa,int tab,int tac){
    int safeSequence[n];
    int al=0;
    int completed=0;
    int a,b,c;
    printf("Enter total of A Resource : ");
    scanf("%d",&a);
    printf("Enter total of B Resource : ");
    scanf("%d",&b);
    printf("Enter total of C Resource : ");
    scanf("%d",&c);
    taa=a-taa;
    tab=a-tab;
    tac=a-tac;
    while(completed!=n){
        for(int i=0;i<n;i++){
            if(!p[i].cs && p[i].remneed[0]<=taa && p[i].remneed[1]<=tab && p[i].remneed[2]<=tac){
                p[i].cs=true;
                taa+=p[i].allocated[0];
                tab+=p[i].allocated[1];
                tac+=p[i].allocated[2];
                safeSequence[al]=p[i].pid;
                al++;
                completed++;
            }
            if(i==n-1 && al==0){
                printf("Deadlock will occur in this Allocations");
            }
        }
    }
    printf("\n\nSafety Sequence : ");
    for(int i=0;i<n;i++){
        printf("%d",safeSequence[i]);
        if(i<n-1){
            printf("->");
        }
    }
    showTable(p,n);
}

 int main(){
    int n,taa=0,tab=0,tac=0;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    struct Process p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter Process %d Allocated Resources (A,B,C) : ",i+1);
        for(int j=0;j<3;j++){
            scanf("%d",&p[i].allocated[j]);
            if(j==0){
                taa+=p[i].allocated[j];
            }
            else if(j==1){
                tab+=p[i].allocated[j];
            }
            else  {  
                tac+=p[i].allocated[j];
            }
        }
        printf("Enter Process %d Maximum Need of Resources (A,B,C) : ",i+1);
        for(int k=0;k<3;k++){
            scanf("%d",&p[i].maxneed[k]);
            p[i].remneed[i]=p[i].maxneed[k]-p[i].allocated[k];
        }
        p[i].cs=false;
    }
    safetyAlgorithm(p,n,taa,tab,tac);
    showTable(p,n);  
    return 0;
 }