#include<bits/stdc++.h>
using namespace std;

void generateBinaryStrings(int k,string fin,int index){
    if(index==k){
        cout<<fin<<" ";
        return;
    }
    fin+="0";
    generateBinaryStrings(k,fin,index+1);
    fin.pop_back();
    fin+="1";
    generateBinaryStrings(k,fin,index+1);
}

int main(){
    int x;
    cin>> x;
    string fin="";
    generateBinaryStrings(x,fin,0);
}