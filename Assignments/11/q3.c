/*You are given an array of n integers.You are supposed to perform n−1 operations on the array.
In one operation you can:
• Delete one element from the array, and add the value of the deleted element to all other
elements in the array.
Find the maximum possible value of the last element after all the operations.
Input
The first line of input contains two space separated integers n (1 ≤ n ≤ 105
).
The second line of input contains n integers a1, a2, . . . , an (1 ≤ x ≤ 103
).
Output
The output should contain one integer, the maximum possible value of the last element.
input
6
2 2 2 3 3 3
output
92
explanation
2 2 2 3 3 3 -> 5 5 5 6 6 -> 11 11 11 12 -> 23 23 23 -> 46 46 -> 92
input
4
2 2 2 2
output
16
explanation
2 2 2 2 -> 4 4 4 -> 8 8 -> 16
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //sort the array:
    for(int i=0;i<n-1;i++){
        int min=arr[i];
        int flag=i;
        for(int j=i+1;j<n;j++){
            if(min>arr[j]){
                min=arr[j];
                flag=j;
            }
        }
        int temp=arr[flag];
        arr[flag]=arr[i];
        arr[i]=temp;
    }
    //calculating sum;
    int sum=0;
    while(n>1){
        int add=arr[n-1];
        for(int i=0;i<n;i++){
            arr[i]+=add;
        }
        n--;
    }
    printf("%d",arr[0]);
}