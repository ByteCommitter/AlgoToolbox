#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char s[100000];
    scanf("%s",s);
    
    char stack[10000];
    int top=-1;

    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('){
            top++;
            stack[top]='(';
        }
        else if(s[i]=='{'){
            stack[++top]='{';
        }
        else if(s[i]=='['){
            stack[++top]='[';
        }
        else if(s[i]==']'){
            if(stack[top]=='['){
                top--;
                continue;
            }
            else{
                printf("NO");
                return 0;
            }
        }
        else if(s[i]=='}'){
            if(stack[top]=='{'){
                top--;
                continue;
            }
            else{
                printf("NO");
                return 0;
            }
        }
        else if(s[i]==')'){
            if(stack[top]=='('){
                top--;
                continue;
            }
            else{
                printf("NO");
                return 0;
            }
        }
    }

    printf("YES");

}