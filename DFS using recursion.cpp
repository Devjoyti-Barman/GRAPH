/*
 https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
*/

#include<bits/stdc++.h>
using namespace std;


bool vis[10005];
void dfs(vector<int>g[],int src,vector<int>&ans){
     
     ans.push_back(src);
     vis[src]=true;
     for(int x:g[src]){
         if(vis[x]==false)dfs(g,x,ans);
     }
     
}
vector <int> solve(vector<int> g[], int N)
{
    
    vector<int>ans;
    if(N==0)return ans;
    memset(vis,false,sizeof vis);
    dfs(g,0,ans);
    return ans;

}



int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];

        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = solve(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  