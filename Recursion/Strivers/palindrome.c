#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void isPalindrome(char s[1000],int i, int j){
    if(i==j || i>j){
        printf("YESS");
        return;
    }
    if(s[i]!=s[j]){
        printf("NOO!");
        return ;
    }
    isPalindrome(s,i+1,j-1);
}

int main(){
    
    char s[1000];
    scanf("%s",&s);
    int len=strlen(s);
    s[len]='\0';
    isPalindrome(s,0,len-1);

}