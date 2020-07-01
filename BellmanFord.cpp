#include<bits/stdc++.h>
using namespace std;
#define w(t) int t;cin>>t;while(t--)
#define pb   push_back
#define mk   make_pair
#define u_s  unordered_set 
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define inf 0x3f3f 
typedef long long int ll;
typedef pair<int,int>ipair;
const ll mod=1e9+7;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.first;
}

void BellmanFord(vector<ipair>graph[],int V,int src){

   vector<int>dist(V,INT_MAX);
   dist[src]=0;

   for(int i=0;i<V-1;i++){
        
        for(int u=0;u<V;u++){

             for(auto x:graph[u]){

                  int v=x.first;
                  int wei=x.second;

                  if(dist[u]!=INT_MAX and dist[u]+wei<dist[v]){
                      dist[v]=dist[u]+wei;
                  }
             }
        }

   }

     for(int i=0;i<V;i++){
         
         if(src==i)continue;
         if(dist[i]==INT_MAX){
            cout<<-1<<" ";
            continue;
         }
         cout<<dist[i]<<" ";
     }
cout<<endl;
}


int main()
{
  
     ios_base::sync_with_stdio(false); 
     cin.tie(nullptr); 
     cout.tie(nullptr);
     
    w(t){ 
            int V,E;cin>>V>>E;
            vector<ipair>graph[V];
            while(E--){
     
                  int u,v,w;
                  cin>>u>>v>>w;
                  graph[u-1].pb(mk(v-1,w));
                  graph[v-1].pb(mk(u-1,w));
            }
            int src;cin>>src;
     
          BellmanFord(graph,V,src-1);
    }

return 0;  
    
}
