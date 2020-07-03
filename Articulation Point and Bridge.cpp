/*
// articulation point
  lowest[child]>=discovery[x]
// articulation Bridge
  
  lowest[child]>discovery[x]

*/

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

const int N=100005,M=22;

vector<int>graph[N];

int disc[N],low[N],tim;
set<int>art_p;
vector<ipair>bridge;

void dfs(int cur,int par){

     disc[cur]=low[cur]=tim++;
      int no_child=0;
     for(auto child:graph[cur]){
        // not visited
        if(disc[child]==0){
          dfs(child,cur);
          no_child++;
          low[cur]=min(low[cur],low[child]);
          
          // art point
          if( par!=0 and low[child]>=disc[child]){
            art_p.insert(cur);
          }
           // bridge
          if(low[child]>disc[cur])
            bridge.pb({cur,child});

        }else if(child!=par){
            // backedge
            // cycle found
            low[cur]=min(low[cur],disc[child]);  
        }
     }
     // seperate case for root to be articulation point
     if(par==0 and no_child>=2)
      art_p.insert(cur);
}



void solve(){

int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
       int x,y;
       cin>>x>>y;
       graph[x].pb(y);
       graph[y].pb(x);
    }
    tim=1;
   dfs(1,0);
   for(auto x:art_p)cout<<x<<" ";
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
     
    solve();
     return 0;  
    
}
