/* The following is the c++ implementation of DF traversal of a graph

Created by : Arnab Chanda
            01.09.2019

*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int value;
        list<int> *edges;
    
        Graph(int val){

            value = val;
            edges = new list<int>[val];
        }
        void initialise_edges(int val1,int val2){
            
            edges[val1].push_back(val2);
        }

        void dfs_traversal(int s, bool visited[] ){
            visited[s] = true;
            cout<<s<<" ";

            for(auto i = edges[s].begin();i!=edges[s].end();++i){
                if(!visited[*i])
                dfs_traversal(*i,visited);
            }
        }

        void dfs(int s){
            bool visited[value];

            for(int i = 0;i<value;i++){
                visited[i] = false;
            }

            dfs_traversal(s,visited);
        }
};

//driver code
int main(){
    cout<<"DEPTH FIRST TRAVERSAL"<<endl;
    cout<<"Enter the number of vertices in the graph: "<<endl;
    int n;
    int start;
    int edges;
    cin>>n;
    Graph g = Graph(n);
    
    cout<<"Enter the edges of the graph: "<<endl;

    cin>>edges;
    while(edges-->0){
        int x,y;
        cin>>x>>y;
        g.initialise_edges(x,y);
        //for bidirected graph add the following line 
        //g.initialise_edges(y,x);
    }
    cout<<"Enter the starting element: "<<endl;
    cin>>start;

    g.dfs(start);
    return 0;
}