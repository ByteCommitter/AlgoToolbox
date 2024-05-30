/*
Walter White in the parallel universe loved math. In search of hefty questions and complex
equations, he walked across the huge valleys of New Mexico. While travelling, he found a boundless
gate. In order to cross the gate, he was supposed to enter a password. He found 3 scrolls lying on
the side of the gate. Two scrolls had some numbers written on them and the third one had some
instructions:
In order to open the door,
These rules you must adore;
And if you do not pass,
You shall not be allowed to explore.
There are two scrolls in which verse,
Two numbers in reverse;
And for passing through the gate,
The sum of the original numbers you must rehearse.
Past the gate is a fog of mist,
Which is achievable only through the use of Linked List;
The sum should be in a new one although, reversed,
And that’s all there is to this valley’s twist.
Help Walter White find the formula to decipher the scrolls and go past the boundless door in
order to cultivate his love for math.
Input
The first line contains 2 positive integers n and m (1 ≤ n, m ≤ 106
) - the number of digits in the
two scrolls respectively.
The second line contains n digits of an integer a in reverse order, where each digit in a is from 0 to
9, both inclusive.
The third line contains m digits of an integer b in reverse order, where each digit in b is from 0 to
9, both inclusive.
Note: The last digit in each of the inputs of second and third line will NOT be 0.
Output
A linked list, consisting of the the sum of the original numbers, but in reverse.
Note: There should be no extra zeros in the end.
2
input
4 5
3 4 5 2
2 9 1 0 2
output
5 3 7 2 2
input
2 2
4 6
6 3
output
0 0 1
*/


#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node* insertNode(int x, struct Node *l1){
    struct Node * newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = x;

    if (l1 == NULL) {
        return newNode;
    }

    struct Node * current = l1;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;

    return current;
}

void printLinkedList(struct Node* head){
    while(head!=NULL){
        int x=head->data;
        printf("%d",x);
        head=head->next;
    }
}

int main(){
    int m, n;
    scanf("%d %d",&m,&n);
    struct Node* l1=malloc(sizeof(struct Node));
    struct Node* l2=malloc(sizeof(struct Node));
    l1=NULL;
    l2=NULL;
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        l1=insertNode(x,l1);
    }
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        l2=insertNode(x,l2);
    }

    //we now have two linked lists created...
    int carry=0;
    struct Node* res=malloc(sizeof(struct Node));
    res=NULL;
    while(l1!=NULL || l2!=NULL){
        int x=0,y=0;
        if(l1!=NULL){
            x=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            y=l2->data;
            l2=l2->next;
        }
        int sum=x+y+carry;
        if (sum>=10){
            carry=1;
        }
        else{
            carry=0;
        }
        sum=sum%10;
        res=insertNode(sum,res);
    }
    printLinkedList(res);
}