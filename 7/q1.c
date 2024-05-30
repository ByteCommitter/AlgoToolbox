#include<stdio.h>
#include<stdlib.h>

void printChar(int num){
    if(num==0){
            printf("0");
        }
        else if(num==1){
            printf("1");
        }
        else if(num==2){
            printf("2");
        }
        else if(num==3){
            printf("3");
        }
        else if(num==4){
            printf("4");
        }
        else if(num==5){
            printf("5");
        }
        else if(num==6){
            printf("6");
        }
        else if(num==7){
            printf("7");
        }
        else if(num==8){
            printf("8");
        }
        else if(num==9){
            printf("9");
        }
        else if(num==10){
            printf("A");
        }
        else if(num==11){
            printf("B");
        }
        else if(num==12){
            printf("C");
        }
        else if(num==13){
            printf("D");
        }
        else if(num==14){
            printf("E");
        }
        else if(num==15){
            printf("F");
        }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char arr[n+1];
    for(int i=0;i<n;i++){
        scanf(" %s",&arr[i]);
    }
    arr[n]='\0';
    int tally[16];
    for(int i=0;i<16;i++){
        tally[i]=0;
    }
    for(int i=0;i<n;i++){
        if(arr[i]=='0'){
            tally[0]++;
        }
        else if(arr[i]=='1'){
            tally[1]++;
        }
        else if(arr[i]=='2'){
            tally[2]++;
        }
        else if(arr[i]=='3'){
            tally[3]++;
        }
        else if(arr[i]=='4'){
            tally[4]++;
        }
        else if(arr[i]=='5'){
            tally[5]++;
        }
        else if(arr[i]=='6'){
            tally[6]++;
        }
        else if(arr[i]=='7'){
            tally[7]++;
        }
        else if(arr[i]=='8'){
            tally[8]++;
        }
        else if(arr[i]=='9'){
            tally[9]++;
        }
        else if(arr[i]=='A'){
            tally[10]++;
        }
        else if(arr[i]=='B'){
            tally[11]++;
        }
        else if(arr[i]=='C'){
            tally[12]++;
        }
        else if(arr[i]=='D'){
            tally[13]++;
        }
        else if(arr[i]=='E'){
            tally[14]++;
        }
        else if(arr[i]=='F'){
            tally[15]++;
        }
    }
    for(int i=0;i<n;i++){
        printf("%s",arr[i]);
    }
    for(int i=0;i<16;i++){
        while(tally[i]>0){
            //printf("%d ",i);
            printf("%s",arr[i]);
            printf(" ");
            tally[i]--;
        }
    }
}