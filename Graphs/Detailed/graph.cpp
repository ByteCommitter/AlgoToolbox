#include<iostream>
#include<bits/stdc++.h>


int main(){
    //Storing and representing graphs
    int n,m;
    cin>> n>>m;
    //n nodes
    //m edges
    //will be given m lines to represent the edges...

    //Primarily two ways to represented in two ways:
    //1. Using Adjacency Lists
    //2. Using Adjacency Matrix

    //adjacency matrices:
    int adjm[n+1][n+1];
    //not very space effecient, n^2
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    //adjacency lists:
    //it's like an array, a special type of array
    vector<int> adjl[n+1];
    
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adjm[x].push_back(y);
        adjm[y].push_back(x);//skip either of tem for an adjacent list
    }

    // if the graph is weighted, then we create a function to store the weight in case of an adjacency list.
    //easier in case of an adjacency matrix, instead of storing 1, we could store the weight.
    
}