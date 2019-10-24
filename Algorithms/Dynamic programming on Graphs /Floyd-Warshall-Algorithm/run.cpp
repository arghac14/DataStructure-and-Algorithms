/*
    Floyd Warshall algorithm 

Floyd Warshall algorithm helps to find the shortest pair path between all the points in a graph.
Below is the c++ implementation of the algorithm.

Time complexity: O(n*n*n)

Created by: Arnab Chanda,14.08.2019

*/

#include <bits/stdc++.h> 

using namespace std;

int adjacencymatrix[1000][1000];
int d[1000][1000];

void printMatrix(int nodes){

    //printing the matrix
    cout<<"The final path matrix : "<<endl;
    for(int i = 0;i<nodes;i++){
        for(int j = 0;j<nodes;j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}

void floyd_warshall(int nodes){
    //copying the contents of adjacency matrix into the array d
    for(int i = 0;i<nodes;i++){
        for(int j = 0;j<nodes;j++){
            d[i][j] = adjacencymatrix[i][j];
        }
    }

    //running the algorithm where the formula is 
    //if the distance between point a to b via c is shorter than distance between point a and b then we replace the direct path value with the shorter value
    // here k represents the intermediate node
    for(int k = 0;k<nodes;k++){
        for(int i = 0;i<nodes;i++){
            for(int j = 0;j<nodes;j++){
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }
    printMatrix(nodes);
}

int main(){
    
    int nodes;
    cout<<"Floyd Warshall Algorithm"<<endl;
    cout<<"Enter the number of nodes in the graph: "<<endl;
    cin>>nodes;
    
    //filling the adjacency matrix with 0
    for(int i = 0;i<nodes;i++){
        for(int j = 0;j<nodes;j++){
            adjacencymatrix[i][j] = 0;
        }
    }

    //taking input of the nodes
    int x;
    for(int i = 0;i<nodes;i++){
        for(int j = 0;j<nodes;j++){
            cout<<"State the relationship between"<<i<<"and "<<j<<" : \n";
            cin>>x;
            if(x>=0){
                adjacencymatrix[i][j] = x;
            }
        }
    }

    //print the adjacency matrix 
    for(int i = 0;i<nodes;i++){
        for(int j = 0;j<nodes;j++){
            cout<<adjacencymatrix[i][j]<<" ";
        }
        cout<<endl;
    }

    floyd_warshall(nodes);
    
    return 0;
}