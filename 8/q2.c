/*
Kira was solving too much CoderAt problems recently, which led to him having a blurry vision.
Due to this his doctor gave him special specs to see arrays, but he could just see k contiguous
elements at once. Since the rich guy he is, he decided to take an array of money, and find the
maximum money he could get from each k-sized window he could observe.
Input
The first line contains two integers n and k (1 ≤ k ≤ n ≤ 106
) - the number of elements in the
array and the size of window visible to Kira respectively.
The second line contains n integers a1, a2, . . . , an (10−9 ≤ ai ≤ 109
).
Output
n − k + 1 space separated integers containing the maximum in each window.
*/

#include<stdio.h>
#include<stdlib.h>

int que[1000];
int front=-1;
int end=-1;
void enqueue(int x){
    if(end==999){
        printf("OverFlow!!");
    }
    else{
        if(front==-1){
            front=0;
        }     
        end++;
        que[end]=x;
    }
}

void dequeue(){
    if(front==-1){
        printf("UnderFlow!!");
    }
    else{
        //printf("%d",que[front]);
        front++;
    }
}

int isEmpty(){
    if(end==-1){
        return 1;
    }
    return 0;
}   

int findMax(){
    int max=que[front];
    for(int i=front;i<=end;i++){
        //printf(" %d ",que[i]);
        if(max<que[i]){
            max=que[i];
        }
    }
    int d=max;
    return d;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        enqueue(arr[i]);
        //printf("\nFront: %d end: %d\n",front,end);
        if(i>=k-1){
            int x=findMax();
            printf("%d ",x);
            dequeue();
        }
    }
    return 0;
}