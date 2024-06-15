/*
Soomitra is the best developer. He was starting his SI cope arc. He felt the DSA labsheets are
too easy for his level and approached Kira. Kira got very angry and told him to implement Min
Stack and Avg Queue. Soomitra being too pro, wanted to implement both of them in the same
code. Kira saw this and told him to use Heaps to implement these Datastructures. Will Soomitra
be able to overcome this challenge.
Formally, implement a FILO stack which can push/pop/getmin in O(1), and also implement a
FIFO queue which can push/pop/getavg in O(1) (min implies min of all elements currently in
stack, similarly avg implies avg of all elements currently in queue). Also you need to use heaps to
implement stack and queue (Give priority based on time of insertion).
Input
The first line contains a single integer q (1 ≤ q ≤ 106
) - the number of queries.
The following q lines are of the following format:
• 1 x : push x into both the queue and the stack.
• 2 : pop from both the queue and the stack.
• 3 : print the minimum element of the stack and the average of all elements in the queue.
Output
For each query of form 3, print min and avg on a new line. (avg rounded down to nearest integer)
input explanation
11 Stack Queue
1 3 3 3
1 7 3 7 3 7
1 6 3 7 6 3 7 6
1 4 3 7 6 4 3 7 6 4
3 min = 3 avg = 5
2 3 7 6 7 6 4
1 1 3 7 6 1 7 6 4 1
3 min = 1 avg = 4
2 3 7 6 6 4 1
2 3 7 4 1
3 min = 3 avg = 2
output
3 5
1 4
3 2

*/

#include<stdio.h>
#include<stdlib.h>

int stack[1000];
int top=-1;

int que[1000];
int front=-1,end=-1;

void enque(int x){
    if(front==-1){
        front=0;
    }
    end++;
    que[end]=x;
}

void deque(){
    //printf("%d",que[front]);
    front++;
}

void pop(){
    int del=stack[top];
    top--;
    //printf("%d",del);
}

void insert(int x){
    top++;
    stack[top]=x;
}

void stackTraverse(){
    int min=stack[0];
    for(int i=0;i<=top;i++){
        if(min>stack[i]){
            min=stack[i];
        }
    }
    printf("min= %d  ",min);
}

void queTraverse(){
    int sum=0;
    for(int i=front;i<=end;i++){
        sum+=que[i];
    }
    int n=end-front+1;
    printf("Average %d",(sum/n));
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int q;
        scanf("%d",&q);
        if(q==1){
            int ent;
            scanf("%d",&ent);
            enque(ent);
            insert(ent);
        }   
        else if(q==2){
            pop();
            deque();
        }
        else if(q==3){
            stackTraverse();
            queTraverse();
        }
        else{
            printf("Incorrect Input!!");
        }
    }
}

/*
test case:

11 
1 3
1 7
1 6
1 4
1 1
3
2
1 1
3
2
2
3*/