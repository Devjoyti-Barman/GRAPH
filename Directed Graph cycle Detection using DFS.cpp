/*
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

*/
/*
   Here in vis[]==

   1. 0 means that, that node is not visited
   2. 1 means that, that node is visited but not explore (and thats our condition) 
   3. 2 means that,that node is visited and explore

*/

#include <bits/stdc++.h>
using namespace std;


bool dfs(int i,int V,vector<int> adj[],vector<int> &vis) {
    vis[i] =1;
    for(auto neigh:adj[i]) {
        if(vis[neigh] == 1)
        return true;
        
        if(vis[neigh]==0 and dfs(neigh,V,adj,vis))
        return true;
    }
    vis[i] =2;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V,0);
    
    for(int i=0;i<V;i++) {
        if(vis[i]==0) {
            if(dfs(i,V,adj,vis)==true)
                return true;
        }
    }
    
    return false;
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