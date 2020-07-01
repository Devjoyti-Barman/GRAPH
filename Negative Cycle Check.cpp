// Here src vertex is zero
#include<bits/stdc++.h>
using namespace std;
#define w(t) int t;cin>>t;while(t--)
#define pb   push_back
#define mk   make_pair
#define u_s  unordered_set 
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
typedef long long int ll;
typedef pair<int,int>ipair;
const ll mod=1e9+7;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.first;
}
void add(vector<ipair>adj[],int u,int v,int w){
     adj[u].pb(mk(v,w));
}

void Bellman_ford(vector<ipair>adj[],int src,int n,int e){
     vector<int>dis(n,INT_MAX);
     dis[src]=0;
     //Relax very edge n-1 times
     for(int i=0;i<n-1;i++){

         for(int u=0;u<n;u++){

              for(auto k:adj[u]){
                  int v=k.first;
                  int wt=k.second;
                  if(dis[u]!=INT_MAX and dis[u]+wt<dis[v]){
                       dis[v]=dis[u] + wt;
                  }
              }
         }
     }
     bool neg_cycle=false;
   for(int u=0;u<n;u++){

        for(auto k:adj[u]){
            int v=k.first;
            int wt=k.second;
            if(dis[u]!=INT_MAX and dis[u]+wt<dis[v])
                 neg_cycle=true;
            
        }
    }
   
   if(neg_cycle){
    cout<<1<<endl;
   }else{
      cout<<0<<endl;
   }

}


int main()
{
	   #ifndef ONLINE_JUDGE
	   freopen("input.txt","r",stdin);
	   freopen("output.txt","w",stdout);
	   #endif
	   ios_base::sync_with_stdio(false); 
	   cin.tie(nullptr); 
	   cout.tie(nullptr);
     

     
     w(t){
          
          int v,e;cin>>v>>e;
          vector<ipair>path[v];
          for(int i=0;i<e;i++){
              int x,y,w;cin>>x>>y>>w;
              add(path,x,y,w);
          }
          Bellman_ford(path,0,v,e);
     }
    
    return 0;
    
}


