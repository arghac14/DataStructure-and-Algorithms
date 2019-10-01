/* Dijkstra Algorithm - Shortest path between two single points algorithm 

Time complexity Worst case  = O(n*n)

Created by: Arnab Chanda 
            21.08.2019

*/

#include<bits/stdc++.h>

using namespace std;

int edgelist[10000][3];

map<int,int> nodevalues;
map<int,int> finalresult;

//function to print the result 
void printresult(){
    map<int,int>::iterator itr;
    for(itr = finalresult.begin();itr!=finalresult.end();++itr){
        cout<<"The distance between the starting node and "<<itr->first<<" is : "<<itr->second<<endl;
    }
}

//function that runs the dijkstra algorithm
void dijkstra(int startingnode, int nodes, int edge){
    map<int,int>::iterator itr;
    while(finalresult.size()<nodes-1){

        int min = 99999999;
        int nextNode;
        for(itr = nodevalues.begin();itr!=nodevalues.end();++itr){
            if(itr->second<min && (finalresult.find(itr->first)==finalresult.end())){
                min = itr->second;
                nextNode = itr->first;
                finalresult.insert(pair<int,int>(nextNode,min));
            }
        }
        for(int i = 0;i<edge;i++){
            if(edgelist[i][0] == nextNode){
                if(min+edgelist[i][2]<nodevalues.find(edgelist[i][1])->second){
                    nodevalues[edgelist[i][1]] = min+edgelist[i][2];
                }
            }
        }
    }
    printresult();
}



int main(){
    
    //input the number of nodes 
    int nodes;
    cout<<"Dijkstra Algorithm"<<endl;
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
    cout<<"Enter the value of the edges where the first number is the starting vertex of the edge the second \nis the endung vertex and the third is the weight of the eddge"<<endl;
    for(int i = 0;i<edges;i++){
        cin>>edgelist[i][0]>>edgelist[i][1]>>edgelist[i][2];
            if (edgelist[i][0] == starting_node){
                nodevalues.insert(pair<int,int>(edgelist[i][1],edgelist[i][2]));
            }
            else{
                nodevalues.insert(pair<int,int>(edgelist[i][1],99999));
            }
        
    }
    cout<<"All inputs taken!"<<endl;
    
    dijkstra(starting_node,nodes,edges);
    
    return 0;
}
