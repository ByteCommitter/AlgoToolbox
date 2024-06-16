#include<iostream>
#include<vector>
using namespace std;

void BinarySearch(int search,vector<int> arr){
    int low=0;
    int high=arr.size();
    while(low<high){
        int mid=(low+high)/2;
        if(search==arr[mid]){
            cout<<mid+1;
            return;
        }
        else if(search>arr[mid]){
            low=mid+1;
        }
        else if(search<arr[mid]){
            high=mid-1;
        }
        else{
            cout<<"-1";
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int vector<int> a;
    for(int i=0;i<n;i++){
        int x
        cin>>x;
        a.push_back(x);
    }
    
    // We should find m, so we implement a binary search on the vector and display the index number acc to 1-indexing
    BinarySearch(m,a);
}
