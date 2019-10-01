/* This is an algorithm to do breadth first traversal of a graph.

    Written by : Arnab Chanda
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
        void bfs(int s){

            list<int>queue;
            bool visited[value];
            for(int  i =0;i<value;i++){
                visited[i] = false;
            }
            visited[s] = true;
            queue.push_back(s);
            while(!queue.empty()){

                int vertex = queue.front();
                queue.pop_front();

                cout<<vertex<<" ";

                for(auto i = edges[vertex].begin();i!=edges[vertex].end();++i){
                    if(visited[*i] == false){
                        visited[*i] = true;
                        queue.push_back(*i);
                    }
                }
            }

        }
};

//driver function
int main(){
    cout<<"BREAD FIRST TRAVERSAL"<<endl;
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

    g.bfs(start);
}

