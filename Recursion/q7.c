/*
Monis loves doing multiplication. He loves multiplication so much that he mastered Karatsuba
Algorithm too. Now, he decided to multiply strings. He defined string multiplication as x∗ a where
x is a positive integer and a is a string. For example, 5 ∗ “ab” = “ababababab” or 3 ∗ “v” = “vvv”.
A string a is divisible by b, if there exists a positive integer x where b ∗ x = a. Also, LCM of
two strings a and b (defined as LCM(a, b)) is the shortest non-empty string that is divisible by
both a and b.
Monis gives you two strings a and b and asks you to find LCM(a, b). If LCM does not exist,
return -1.
Input
The first line contains a single string a (1 ≤ |a| ≤ 106
).
The second line contains a single string b (1 ≤ |b| ≤ 106
).
Output
A single string which is LCM(a, b), if it exists. Otherwise -1.
input
ab
abab
output
abab
input
ccc
cc
output
cccccc
input
abc
d
output
-1
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char a[1000],b[1000];
    scanf("%s",a);
    scanf("%s",b);
    int lena=strlen(a);
    int lenb=strlen(b);
    a[lena]='\0';
    b[lenb]='\0';

    if(lena<=lenb){
        for(int i=0;i<lena;i++){
            int flag=0;
            for(int j=0;j<lenb;j++){
                if(a[i]==b[j]){
                    flag++;
                    break;
                }
            }
            if(flag==0){
                printf("-1");
                return 0;
            }
        }
        int i=1;
        char res[1000];
        for(int i=0;i<lena;i++){
            res[i]=a[i];
        }
        while(i<=(lena)){
            for(int j=i*lena;j<(i+1)*lena;j++){
                res[j]=a[j%lena];
            }
            if(i<lenb){
                continue;
            }
            /*for(int j=0;j<strlen(res);j++){
                if(res[j]!=b[j%lenb]){
                    printf("-1");
                    return 0;
                }
            }*/
            printf("%s\n",res);
            return 0;
        }
        printf("-1");
    }
}