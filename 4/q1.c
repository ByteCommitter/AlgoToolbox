/*
Shimmerun was writing an article on LiFi (Light Fidelity) Technology. Halfway through, she
realised that the numbers she wrote were supposed to be written down using the International
Number System in the English Language (without any and, and in lower case).
Help Shimmerun make the edits, so that all of you can read about the LiFi Technology.
Input
The first line contains a single non-negative integer n (0 ≤ n ≤ 1012).
Output
A lowercase string representing the integer number above (without any and).
input
10
output
ten
input
673
output
six hundred seventy three
input
1234567
output
one million two hundred thirty four thousand five hundred sixty seven
*/

#include<stdio.h>
#include<stdlib.h>

void thousand(int x){

    printf(" thousand ");
}
void tens(int x){
    switch(x){
        case(1):
            printf("ten");
        case(2):
            printf("twenty");
        case(3):
            printf("thirty");
        case(4):
            printf("forty");
        case(5):
            printf("fifty");
        case(6):
            printf("sixty");
        case(7):
            printf("seventy");
        case(8):
            printf("eighty");
        case(9):
            printf("ninety");
    }
}

void numbers(int x){
    switch(x){
        case(1):
            printf("one");
        case(2):
            printf("two");
        case(3):
            printf("three");
        case(4):
            printf("four");
        case(5):
            printf("five");
        case(6):
            printf("six");
        case(7):
            printf("seven");
        case(8):
            printf("eight");
        case(9):
            printf("nine");
    }
}

void million(int x){

}
int main(){
    string m=" Million ";
    string b=" Billion ";
    string tr=" Trillion ";
    string t=" Thousand ";

    
}