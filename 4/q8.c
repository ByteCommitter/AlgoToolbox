#include<stdio.h>
#include<string.h>

void solve(int n, int a ,int b){
    char result[n+1];
    memset(result,'K',n);
    result[n]='\0';

    if(b==1){
        result[a]='O';
    }
    else{
        for(int i=0;i<b-1;i++){
            int part=a/b;
            int rem=a%b;
            result[(i+1)*part+i+rem]='O';
        }
    }

    printf("%s",result);
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    solve(n, a, b);
    return 0;
}