/*
Nom woke up from his deep sleep and decides to build a giant pile of Peanut Butter so he can
eat it before and after sleeping without having to move from his place. He goes to a store, which
has n distinct types of jars of Peanut Butter available with infinite supply for each type of jar. Each
type of jar has a different weight(in kgs). You have to help Nom find the total number of ways he
can select the jars, such that the total weight of Peanut Butter that he eats is k kgs.
Note: The order of the jars does not matter.
Input
The first line contains 2 integers n and k (1 ≤ n ≤ 20; 1 ≤ k ≤ 25).
The second line contains n distinct weights of jars sold at the store a1, a2, . . . , an (1 ≤ ai ≤ 20).
Output
Find the number of ways in which Nom can select the jars.
input
3 9
2 3 5
output
3
Explanation: There are 3 different combinations possible :- (2,2,2,3) , (3,3,3) , (2,2,5). There
are no other combinations which add up to 9 (Order doesn’t matter).
*/

#include<stdio.h>

void Count(int i,int n, int target,int jars[],int *cnt){
    if(i==n){
        if(target==0){
            *cnt+=1;
        }
        return;
    }
    if (jars[i] <= target) {
        Count(i, n, target - jars[i], jars, cnt);
    }
    Count(i + 1, n, target, jars, cnt);  
}

int main(){
    int n,target;
    scanf("%d %d",&n,&target);
    int jars[n];
    for(int i=0;i<n;i++){
        scanf("%d",&jars[i]);
    }
    int cnt=0;
    Count(0,n,target,jars,&cnt);
    printf("%d",cnt);
}