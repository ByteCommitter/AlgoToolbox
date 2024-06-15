/*
You are given an n × n matrix. Each cell contains an integer.
Your task is to perform q queries of the form: what is sum of the integers in a given rectangle?
Input
The first input line has two integers n and q: the size of the matrix and the number of queries
(1 ≤ n ≤ 104
, 1 ≤ q ≤ 105
).
Then, there are n lines describing the matrix. Each line has n integers corresponding to the row of
the matrix (1 ≤ Mij ≤ 109
).
Finally, there are q lines describing the queries. Each line has four integers y1, x1, y2, x2 corresponding to the corners of a rectangle (1 ≤ y1, x1, y2, x2 ≤ n).
Output
The qth line of the output should contain the sum of integers inside the corresponding rectangle.
input
3 1
1 2 3
4 5 6
7 8 9
1 1 3 3
output
45
input
4 3
2 5 1 8
3 9 4 2
7 1 6 3
8 2 5 4
1 1 2 2
2 3 3 4
3 1 4 3
output
19
21
29
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int queries[q][4];
    int x1,y1,x2,y2;
    for(int i=0;i<q;i++){
        scanf("%d %d %d %d",y1, x1, y2, x2);
        queries[i][0]=y1;
        queries[i][1]=x2;
        queries[i][2]=y2;
        queries[i][3]=x2;
    }

    while(q>0){
        int sum=0;
        for(int i=;i<=y2-1;i++){
            for(int j=x1-1;j<=x2-1;j++){
                sum+=arr[i][j];
            }
        }
        printf("%d",sum);
        q--;
    }
    
}