#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    deque<int>stones;

    for(int i=0;i<n;i++){
        int u;
        cin>>u;
        stones.push(u);
    }
    //4 5 1 3 4
    //any participant would ideally pick the last element here
    //how could we make sure we pick the last and not the first element??

    //other test case
    //4 8 7 1000 9

    

}