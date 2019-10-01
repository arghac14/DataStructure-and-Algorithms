/*
    Bellman-Ford algorithm 

Bellman-Ford algorithm helps to find the shortest path from one point to all the points in a graph.
Below is the c++ implementation of the algorithm.

Time complexity: O(n*e), where n is the number of nodes in the graph and e is the number of edges 

Created by: Arnab Chanda,17.08.2019

*/

#include<bits/stdc++.h>

using namespace std;

int edgelist[10000][3];
map<int,int> nodevalues;

//functiont o print the shortest path map
void print_shortest_paths(int nodes){
    cout<<"Shortest paths from starting index are as follows :"<<endl;
    map<int,int>::iterator itr;
    for(itr = nodevalues.begin();itr!=nodevalues.end();++itr){
        cout<<itr->first<<"\t"<<itr->second<<endl;
    }
}

void bellman_ford(int starting_node,int nodes,int edges){

    int c;

    //runnung the bellman ford algorithm here
    for (int j = 0;j<nodes;j++){
        c = 0;
        for(int i  = 0;i<edges;i++){
            if(nodevalues.find(edgelist[i][0])->second+edgelist[i][2]<nodevalues.find(edgelist[i][1])->second){
                nodevalues[edgelist[i][1]]=nodevalues.find(edgelist[i][0])->second+edgelist[i][2];
                c++;
            }
        }
        //this part checks for negetive edge cycle in the graph
        if(j == nodes-1 && c>0){
            cout<<"The graph contains negetive edge cycle"<<endl;
        }   
    }
    print_shortest_paths(nodes);
}

int main(){
    
    //input the number of nodes 
    int nodes;
    cout<<"Bellman Ford Algorithm"<<endl;
    cout<<"Enter the number of nodes in the graph: "<<endl;
    cin>>nodes;
    
    //input the starting node
    int starting_node;
    cout<<"Enter the node from which you want to find the shortest path: "<<endl;
    cin>>starting_node;

    //taking input for the number of edges
    int edges;
    cout << "Enter the number of edges in the graph: "<<endl;
    cin>> edges;

    //filling the adjacency matrix with 0
    cout<<"Enter the value of the edges where the first number is the starting vertex of the edge the second \n is the endung vertex and the third is the weight of the eddge"<<endl;
    for(int i = 0;i<edges;i++){
        cin>>edgelist[i][0]>>edgelist[i][1]>>edgelist[i][2];
        if (nodevalues.count(edgelist[i][0]) == 0){
            if (edgelist[i][0] == starting_node){
                nodevalues.insert(pair<int,int>(edgelist[i][0],0));
            }
            else{
                nodevalues.insert(pair<int,int>(edgelist[i][0],99999));
            }
        }
        if (nodevalues.count(edgelist[i][1]) == 0){
            if (edgelist[i][1] == starting_node){
                nodevalues.insert(pair<int,int>(edgelist[i][1],0));
            }
            else{
                nodevalues.insert(pair<int,int>(edgelist[i][1],99999));
            }
        }
    }

    bellman_ford(starting_node,nodes,edges);
    
    return 0;
}