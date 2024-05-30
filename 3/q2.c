#include<stdio.h>
#include<stdlib.h>

int nonRepeat(char a[], int n){
    int charIndex[26];
    for(int i=0;i<26;i++){
        charIndex[i]=-1;
    }
    int k=0;
    int max=0;
    int count=0;
    for(int j=0;a[j]!='\0';j++){
        if(charIndex[a[j]-'a']!=-1 && charIndex[a[j]-'a']>=k){
            k=charIndex[a[j]-'a']+1;
        }
        charIndex[a[j]-'a']=j;
        count=j-k+1;
        if(count>max){
            max=count;
        }
    }
    return max;
}

int main(){
    int n;
    scanf("%d",&n);
    char str[n];
    scanf("%s",str);
    int x=nonRepeat(str,n);
    printf("%d",x);
}