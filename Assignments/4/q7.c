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
*/

#include<stdio.h>
#include<string.h>

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

void charlcm(char *a,char *b){
    int a_len,b_len;
    a_len=strlen(a);
    b_len=strlen(b);
    int lcm_len=(a_len*b_len)/gcd(a_len,b_len);

    char lcmstr[lcm_len+1];

    for(int i=0;i<lcm_len;i++){
        lcmstr[i]=(a[i%a_len]);
    }
    lcmstr[lcm_len]='\0';

    for(int i=0;i<lcm_len;i++){
        if(lcmstr[i]!=b[i%b_len]){
            printf("-1");
            return;
        }
    }
    printf("%s",lcmstr);
    return;
}

int main(){
    char a[1000];
    char b[1000];
    scanf("%s",a);
    scanf("%s",b);
    charlcm(a,b);
}