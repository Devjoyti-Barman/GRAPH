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
int vis[N];

bool odd_cycle=false;

void dfs(int cur,int par,int col){
    
    vis[cur]=col;
    for(auto child:graph[cur]){
        if(vis[child]==0){
          dfs(child,cur,3-col);
        }else if(child!=par and col==vis[child]){
            // backedge and odd length cycle
            odd_cycle=true;
        }
    }
    return;
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
    
   dfs(1,0,1);
   if(odd_cycle){
      cout<<"Not Bipartite\n";
   }else{
      cout<<"Bipartite\n";
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
     
    solve();
     return 0;  
    
}
