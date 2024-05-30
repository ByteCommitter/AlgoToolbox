/*
Further ahead in his journey for peanut butter, Nom suddenly got warped back in the 1910s.
He ended up meeting Einstein. Einstein was solving the Hamiltonian Equation at that moment,
and was in serious need of help of someone to calculate square roots for him. Nom agrees and opens
his laptop, but realises that due to the time travel, he lost all the inbuilt operators. You have to
help Nom find all the square roots without using any inbuilt functions or operators.
Further Einstein tells you both to find the square root upto 6 digits after decimal. No more, no
less and no rounding off.
Input
The first line contains a positive integers N (1 ≤ N ≤ 2
31 − 1) - the number whose square root you
have to find.
Output
A floating-point number with 6 digits after the decimal.
Your solution should run in O(logN) time complexity.
input
245
output
15.652475
input
1
output
1.000000
input
6969
output
83.480536
*/

#include<stdio.h>
#include<stdlib.h>

double ssqrt(int d){
    double mid;
    double start=0,end=d;    
    while(end-start>=0.000001){
        mid=(start+end)/2;
        if(mid*mid>d){
            end=mid;
        }
        else{
            start=mid;
        }
    }
    return mid;
}


int main(){
    int n;
    scanf("%d",&n); 
    double ans;
    ans=ssqrt(n);
    printf("%.6f",ans);
}