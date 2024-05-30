/*
Nom was on a Peanut Butter streak. So he decided to pre-order n jars, 1 for each day. In order
to make it more interesting, he spiced things up a bit. He asked the seller to send random weights.
Now the seller sent him an array with all the jar weights.
Help Nom find another array where he notes down after how many days from the current day
will he be able to have his beloved Peanut Butter whose weight is just greater than the current
day’s jar in the seller’s array. If there is no such jar, assume 0 for that position in the array.
Similarly, Nom wants to find another array where he notes after how many days will he have a
jar whose weight is just lesser than the current day’s jar. In case he starts dieting of course. If
there is no such jar, assume 0 for that position in the array.
Input
The first line contains a single integer n (1 ≤ n ≤ 106
) - the length of the seller’s array.
The second line contains n integers a1, a2, . . . , an (1 ≤ ai ≤ 106
) - weights of the Peanut Butter
jars.
Output
Two arrays of size n in two different lines as described above.
input
4
30 40 50 60
output
1 1 1 0
0 0 0 0
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
    for(int i=0;i<n;i++){
        if(i==n-1){
            printf("0");
            break;
        }
        int cnt=0;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                cnt=j-i;
                break;
            }
        }
        printf("%d ",cnt);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        if(i==n-1){
            printf("0");
            break;
        }
        int cnt=0;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                cnt=j-i;
                break;
            }
        }
        printf("%d ",cnt);
    }
}