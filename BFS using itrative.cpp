/*
https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}



 vector<int>ans;
void BFS(vector<int>g[],vector<bool>&vis,int src){
    queue<int>Q;    
    Q.push(src);
    
    while(!Q.empty()){
       
       int u=Q.front();
       Q.pop();
       ans.push_back(u);
       for(int x: g[u]){
           if(vis[x]==false){
               Q.push(x);
               vis[x]=true;
           }
       }
       
    }

}

vector <int> bfs(vector<int> g[], int N) {
    

   ans.clear();
    if(N==0)return ans;
    vector<bool>vis(N+1);
    BFS(g,vis,0);
    return ans;
}