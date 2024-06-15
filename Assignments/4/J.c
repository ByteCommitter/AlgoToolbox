/*
Vidyateja was bored of making websites, so he decided to tamper with your Connect-4 like
board. Your board had 3 types of cells:
• an empty cell (.).
• an obstacle (o).
• your coin (∗).
Due to his antics, the board is now a complete mess. However, the coins are guaranteed to stay in
their respective columns, appearing in order from top to bottom, but dispersed. Now, you pick up
the board, and all coins fall down until they meet the bottom, an obstacle (an obstacle is immovable
always), or another immovable coin.
You have to find the final position of everthing on the board after the falling process (Looking
at the samples should make it clear).
Input
The first line contains 2 positive integers n and m (1 ≤ n, m ≤ 5000) - the number of rows and
columns in the board.
The consequent n lines contain m characters comprising of an empty cell, an obstacle or a coin.
Output
A grid with n rows and m columns showing the result of the falling process.
input
6 10
.*.*....*.
.*.......*
...o....o.
.*.*....*.
..........
.o......o*
output
..........
...*....*.
.*.o....o.
.*........
.*......**
.o.*....o*
*/

#include<stdio.h>
#include<string.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char arr[n][m];
    for(int i=0;i<n;i++){
            char c[m];
            scanf("%s",c);
            for(int j=0;j<m;j++){
                arr[i][j]=c[j];
            }
    }
    
    //n is for rows, horizontal and m is columsn vertical
    for(int i=0;i<m;i++){
        int cnt_start=0;
        int cnt_poststar=0;
        for(int j=n-1;j>=0;j--){
            if(arr[j][i]=='*'){
                cnt_start++;
            }
            if(arr[j][i]=='o'){
                cnt_poststar++;
                cnt_start=0;
            }
        }
        printf("%d ",cnt_start);
        for(int j=n-1;j>=0;j--){
            if(arr[j][i]=='o'){
                arr[j][i]='o';
            }
            else if(cnt_start>0){
                arr[j][i]='*';
                cnt_start--;
            }
            else if(arr[j][i]=='o'){
                arr[j][i]='o';
            }
            
            else{
                if(cnt_poststar>0){
                    arr[j][i]='*';
                    cnt_poststar--;
                }
                else{
                arr[j][i]='.';
                }
            }
        }
    }

    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}