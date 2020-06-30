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


queue<int>Q;
 vector<int>ans;
void BFS(vector<int>g[],vector<bool>&vis,int src){
     
    vis[src]=true;
    ans.push_back(src);
    for(int x:g[src]){
        if(vis[x]==false){
            Q.push(x);
            vis[x]=true;
        }
    }
    if(Q.empty())return;
    int u=Q.front();
    Q.pop();
    BFS(g,vis,u);

}

vector <int> bfs(vector<int> g[], int N) {
    

   ans.clear();
    if(N==0)return ans;
    vector<bool>vis(N+1);
    BFS(g,vis,0);
    return ans;
}