/*
You have done binary exponentiation before, matrix exponentiation works in a similar way. We
need to find Mp where M is a matrix rather than a number. We define M2 = M ∗ M and thus
Mp = M ∗ M ∗ . . . M ∗ M where M is repeated p times.
Given a matrix M of dimensions NxN, find Mp using Matrix Exponentiation technique.
Input
The first line of input contains two space separated integers N and p (1 ≤ N ≤ 104
, 1 ≤ p ≤ 109
).
The following N lines of input each contains N integers each describing rows of matrix M.
(1 ≤ Mij ≤ 109).
Output
The output should contain N lines, each describing rows of the matrix Mp
.
input
4 2
5 5 5 5
5 5 5 5
5 5 5 5
5 5 5 5
output
100 100 100 100
100 100 100 100
100 100 100 100
100 100 100 100

input
3 1000000000
1 0 0
0 1 0
0 0 1
output
1 0 0
0 1 0
0 0 1
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    int mat[n][n];
    int capy[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
            scanf("%d",&copy[i][j]);
        }
    }
    while(p>0){
        for(int i=0;i<n;i++){
            int sun
            for(int j=0;j<n;j++){

            }
        }
        p--;
    }
}