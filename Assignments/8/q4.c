/*
After not getting IT Placements, you become a Data Analyst. Your Boss gives you 100’s of Histograms a day. All of those Histograms have bars with a width of size 1 and no spaces in between.
One day you record the heights in an array and decide to relive your coding days by trying to find
out the maximum area of any possible rectangle inside of the Histogram.
Input
The first line contains a single integer n (1 ≤ n ≤ 106
) - number of bars in the Histogram.
The second line contains n integers a1, a2, . . . , an (1 ≤ ai ≤ 104
) - heights of the bars.
Output
A single integer - maximum area of all possible rectangles.
input
2
2 4
output
4
input
7
11 70 25 47 30 23 40
outp
*/
#include <stdio.h>
#define MAX 1000000

int que[MAX], top = -1,front=-1,end=-1;

void enque(int x){
    if(front==-1){
        front =0;
    }
    end++;
    que[end]=x;
}

void deque(){
    if(front==-1){
        printf("UnderFlow!");
    }
    else{
        front++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max=0;
    for(int i=0;i<n;i++){
        int area=0;
        int min=arr[i];
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
            }
            area=min*(j-i+1);
            if(max<area){
                max=area;
            }
        }
    }
    printf("%d",max);

    return 0;
}