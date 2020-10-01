#include <bits/stdc++.h>
using namespace std;

/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    vector<int> indegree(V,0);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < adj[i].size(); j++){
            indegree[adj[i][j]]++;
        }        
    }
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(!indegree[i])
            q.push(i);
    }
    int processed = 0;
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i = 0; i < adj[t].size(); i++){
            indegree[adj[t][i]]--;
            if(indegree[adj[t][i]] == 0)
                q.push(adj[t][i]);
        }
        processed++;
    }
    return processed < V;
}


int main() {
	
	int t;
	cin >> t;
	while(t--){
	    int v, e;
	    cin >> v >> e;
	    vector<int> adj[v];
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    cout << isCyclic(v, adj) << endl;   
	}
	return 0;
}  