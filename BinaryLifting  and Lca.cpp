/*
https://cses.fi/problemset/task/1688

*/

#include<bits/stdc++.h>
using namespace std;
#define w(t) int t;cin>>t;while(t--)
#define pb   push_back
#define mk   make_pair
#define u_s  unordered_set
#define endl "\n"
#define prDouble(x) cout<<fixed<<setprecision(12)<<x
#define ll long long
#define ipair pair<int,int>
#define all(x) (x).begin(), (x).end()
const int32_t Mod=1e9+7;

const int mod=1e9+7;

/*
  ctrl+alt+p =preference 
  alt+shift to change laungauge
 */
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.first;
}

void open_file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
}
void fast_io(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


const int Size=200010;

vector<vector<int>>up(Size,vector<int>(30));

vector<int>tree[Size];  
vector<int>level(Size,0);


void dfs(int src,int par,int depth){
 
   up[src][0]=par;
   level[src]=depth;
 
   for(int i=1;i<=18;i++){
 
     if(up[src][i-1]!=-1)up[src][i]=up[up[src][i-1]][i-1];
     else
      up[src][i]=-1;
   }
 
   for(int child:tree[src]){ 
 
        if(child!=par){
 
           dfs(child,src,depth+1);
        }
   }
}

int lift_node(int node,int jump){
     
    for(int i=30;i>=0;i--){
	   
	   int mask=1<<i;
	   
	   // very imp condition
	   if( node==-1 or jump==0 )break;
	   
	   if( jump >= mask ){
	       
	       jump-=mask;
	       node=up[node][i];
	   }
	}
	
	return node;
}



int lca(int u,int v){
	
   if(level[u]<level[v])swap(u,v);
 
   u=lift_node(u,level[u]-level[v]);
   if(u==v)return v;
 
   for(int i=19;i>=0;i--){
 
       if(up[u][i]!=up[v][i]){
           u=up[u][i];
           v=up[v][i];
       }
   }
   return lift_node(u,1);
}



void solve(){
  
  int n,q; cin>>n>>q;
  
  for(int i=2;i<=n;i++){
    int u; cin>>u;
    tree[i].push_back(u);
    tree[u].push_back(i);
  }
  
  dfs(1,-1,0);
  
  while(q--){
	  
	  int u,v; cin>>u>>v;
      cout<< lca(u,v) <<"\n";
  }
  
  
  

}


int main(){ 

  open_file();
  fast_io();
  
  
  solve();
  
  return 0;
}

 
