/*A: Big Sum

Depending on the platform, the largest integer data type in C will allow you to store numbers
that are tens of digits long. In this question, you will write a program that will enable you to add
non-negative integers that are at most a thousand digits long. To this end, create two strings that
can be used to store upto 1000 digit positive integers in base 10; Each digit will be a character
in the usual positional number system. Obtain these numbers as input from the user and assume
that the first number is greater than or equal to the second and that the numbers are non-negative.
Your program should compute their sum and store it in a string without padding zeros to the left.
Also, you should print the sum. Write the entire program in the main() function without having to
write separate functions. Further, you are not allowed to use library functions from the string.h
library.
Input
The first line of input contains the integer A (0  A  101000) represented as a string. The second
line of input contains the integer B (A  B  101000) represented as a string.
Output
Print a single string, representing the sum of two long integers provided to you. Note that, the
output must not be zero padded on the left.*/

#include<stdio.h>

int main(){
    char A[1000], B[1000], sum[1001];

    //split the number is orders of 10 and add them up and add each sum int order of multiples of 10...
    
}