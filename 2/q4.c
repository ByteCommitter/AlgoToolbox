#include<stdio.h>

double find_sqroot(int N){
    double low=0;
    double mid;
    double high= N;
    while(high-low>=0.000001){
        mid=(high+low)/2;
        if(mid*mid>N){
            high=mid;
        }else{
            low=mid;
        }
    }
    return  mid;
}

int main(){
    int N;
    scanf("%d", &N);
    double sqrt = find_sqroot(N);
    printf("%.6lf\n", sqrt);
    return 0;
}