#include<bits/stdc++.h>
using namespace std;

int getHighest(int n){
    int high=INT_MIN;
    while(n>0){
        int rem=n%10;
        high=max(high,rem);
        n=n/10;
    }
    return high;
}

int main(){
    int n;
    cin>>n;
    int cnt=0;
    while(n>0){
        ++cnt;
        int removve=getHighest(n);
        n-=removve;
    }
    cout<<cnt;
}