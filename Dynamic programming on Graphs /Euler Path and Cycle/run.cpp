/* Eulerian graph and existence of a Euler cycle.

Eulerian graph: A graph is called Eulerian graph if we can traverse through the graph touching all its vertexes only once. 
Eulerian cycle: If while trying to prove that the graph is Eulerian or not we start and end at the same vertex then the path is called a Eulerian cycle.

We use DfS to see if the graph is a connected graph or not. 
If  a graph is not connected then it is not Eulerian. To have the existence of a Eulerian cycle in a Eulerian graph, there should not be any odd degree vertices. 

Coded in C++ 

Written by: Arnab Chanda
            04.09.2019

*/

#include<bits/stdc++.h>

using namespace std;

class Graph{
    
    public:

        int v;
        list<int> *adj;

    Graph(int edges){
        v = edges;
        adj = new list<int>[v];
    }

    void add_edge(int x, int y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void dfs(int pos, bool visited[]){
        visited[pos] = true;
        
        for(auto i = adj[pos].begin();i!= adj[pos].end();++i){
            if(visited[*i] == false){
                dfs(*i,visited);
            }
        }
    }

    bool isConnected(){

        bool visited[v];
        int i;

        for(i = 0;i<v;i++){
            visited[i] = false;
        }

        for(i = 0;i<v;i++){
            if(adj[i].size()>0)
            break;
        }

        if(i == v){
            return false;
        }
        
        dfs(i,visited);

        for(i = 0;i<v;i++){
            if(visited[i] == false && adj[i].size()>0){
                return false;
            }
        }

        return true;
    }

    void checkEuler(){
        
        if(isConnected() == false){
            cout<<"Sorry the graph is not an Euler graph"<<endl;
            return;
        }

        int odd = 0;
        for(int i = 0;i<v;i++){
            if(adj[i].size()%2!=0)
            odd++;
        }

        if(odd>2){
            cout<<"The graph is not Eulerian"<<endl;
            return;
        }

        if(odd == 0){
            cout<<"Yes Eulerian cycles are there."<<endl;
        }
        else{
            cout<<"Graph is Eulerian but no cycles"<<endl;
        }
        return;
    }
};

int main(){

    cout<<"EULER GRAPH AND EULER CYCLE"<<endl;
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
        g.add_edge(x,y);
    }

    g.checkEuler();
    return 0;
}