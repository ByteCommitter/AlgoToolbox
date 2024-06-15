/*
Since some people in BITS started to earn a lot of money, the Supreme Court of BITS decided
that whatever income a person gets, the sum of its digits should be equal to k. You wanted to see if
the future income of Jignes follows this law. Given the lower bound l and upper bound r of Jignes’s
salary based on professional estimates, and the digits which Vidyateja found out by breaching his
offer letter (he couldn’t see all the digits at once); find the number of different possible salaries
which Jignes can have (No leading zeros).
Input
The first line contains a four integers n, k, l, r (1 ≤ n ≤ 16; 0 ≤ k ≤ 144; 1 ≤ l ≤ r ≤ 1015).
The second line contains a string of size n. This corresponds to the digits which Vidyateja spotted.
“?” denotes that the digit was not spotted, and can take any valid value.
The number of “?”’s is m. (1 ≤ m ≤ 7)
Output
The number of different possible salaries (without any leading zeros) which Jignes can have.
input
4 5 2000 10000
????
output
20
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef unsigned long long ll;

void predictPossibility(int i,int n, int target, ll lb, ll ub, char csal[],int *count,int *sum,ll *sal){
    if(i==n){
        if(*sum==target && *sal>=lb && *sal<=ub){
            *count+=1;
        }
        return;
    }
    if(csal[i]=='?'){
        for(int j=0;j<7;j++){
            *sum+=(j);
            *sal+=((j)*(ll)pow(10,n-i-1));
            predictPossibility(i+1,n,target,lb,ub,csal,count,sum,sal);
            *sum-=(j);
            *sal-=((j)*(ll)pow(10,n-i-1));
        }
    }
    else{
        predictPossibility(i+1,n,target,lb,ub,csal,count,sum,sal);
    }

}

int main(){
    int n,target;
    ll lb,ub;
    scanf("%d %d %llu %llu",&n,&target,&lb,&ub);
    char csal[n];
    scanf("%s",csal);
    int count=0;
    int sum=0;
    ll sal=0;
    for(int i=0;i<n;i++){
        if(csal[i]!='?'){
            sum+=(csal[i]-'0');
            sal+=((csal[i]-'0')*(ll)pow(10,n-i-1));
        }
    }
    predictPossibility(0,n,target,lb,ub,csal,&count,&sum,&sal);
    printf("%d",count);
}