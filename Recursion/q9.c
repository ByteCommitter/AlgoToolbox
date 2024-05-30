#include<stdio.h>

int stack[1000];
int top=-1;
void push(int x){
    top++;
    stack[top]=x;
}
//getNumbers, pushes all the possibilities onto the stack, which we can later on sort...
void getNumbers(int num[],int index,int n, int target,int sum,int sub[], int subindex){
    if(index==10 || sum>target){
        return ;
    }
    if(subindex==n){
        if(sum==target){
            for(int i=0;i<subindex;i++){
                printf("%d ",sub[i]);
            }
            printf("\n");
        }
        return ;
    }
    getNumbers(num,index+1,n,target,sum,sub,subindex);
    sum+=num[index];
    sub[subindex]=num[index];
    getNumbers(num,index,n,target,sum,sub,subindex+1);
}

int main(){
    int n, target;
    scanf("%d %d",&n,&target);
    int num[10]={9,8,7,6,5,4,3,2,1,0};
    int index=0;
    int sub[20];
    getNumbers(num,index,n,target,0,sub,0);
    for(int i=0;i<=top;i++){
        printf("%d",stack[i]); 
    }
    if(top==-1){
        printf("-1 -1");
        return 0;
    }
    //else we print the maximum and minimum possible...
}