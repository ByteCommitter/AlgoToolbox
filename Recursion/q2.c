/*
A-man and Mahi-man along with their (k−2) friends decide to enter a beauty pageant. In order
to look good, Mahi-man orders n makeup packets, where i-th packet has a weight ai
. Since the
packets are heavy, A-man goes and picks them up. Now he has to distribute them among everyone
including himself. Since it is a makeup packet, it cannot be broken into smaller weights. Also, each
makeup packet is given to someone for sure.
The beauty of a distribution is defined as the maximum weight of makeup obtained by a single person. Hence, help A-man distribute in such a way that the beauty is minimized over all of
the possible distributions (since he hates makeup unlike his friends).
Input
The first line contains 2 integers, n and k (2 ≤ k ≤ n ≤ 8) - the number of makeup packets and the
total number of people respectively.
The second line contains n integers a1, a2, . . . , an (1 ≤ ai ≤ 106
) - the weights of the makeup
packets. These weights need not be unique.
Output
Single integer containing the minimum beauty of all distributions.
input
5 2
8 15 10 20 8
output
31
Explanation: A-man can take the packets (10,20) and give Mahi-man the packets (8,15,8). So
the beauty of this distribution is 31. This is the minimum beauty among all distributions.
input
6 3
9 12 7 3 11 20
output
21
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int min_beauty=INT_MAX;

void checkBeauty(int arr[], int sub[], int index, int subindex, int k, int n){
    if(index==n){
        int max=0;
        for(int i=0;i<k;i++){
            if(sub[i]>max){
                max=sub[i];
            }
        }
        if(max<min_beauty){
            min_beauty=max;
        }
        return;
    }
   
    for(int i=0;i<=subindex;i++){
        sub[i]+=arr[index];
        checkBeauty(arr,sub,index+1,i,k,n);
        sub[i]-=arr[index];
    }
    if(subindex+1<k){
        sub[subindex+1]+=arr[index];
        checkBeauty(arr,sub,index+1,subindex+1,k,n);
        sub[subindex+1]-=arr[index];
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sub[k];
    for(int i=0;i<k;i++){
        sub[i]=0;
    }
    checkBeauty(arr,sub,0,0,k,n);
    printf("%d ",min_beauty);
    return 0;
}