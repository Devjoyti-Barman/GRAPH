/*
https://www.spoj.com/problems/EC_P/
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


bool cmp( pair<int,int>p1, pair<int,int>p2 ) {

     if( p1.first== p2.first ){
	    return p1.second <p2.second;
	 }
	 
	 return p1.first<p2.first;
}

const int Size=1000;

vector<int>in(Size);
vector<int>low(Size);
vector<bool>vis(Size);
int timer=0;

vector<pair<int,int>>bridges;

void dfs(int src,int par,vector<int>graph[]){
     
     vis[src]=true;
     
     in[src]=low[src]=timer++;
     
     for(int child: graph[src]){
	    
	    if( child==par )continue;
	    
	    // if the child is visited
	    if( vis[child]==true ) {
		   // back-edge
		   // what is the largest ancester  node that I can reach
		   low[src]=min( low[src],in[child] );
		}else{
		   
		   dfs(child,src,graph);
		   
		   // what is the largest ancester  node that I can reach
		   
		   // updating the low of src
		   low[src]=min(low[src],low[child]);
		   // this is a articulation bridge
		   if( low[child] > in[src] ){
		       
		       if( child >src)
		         bridges.push_back({src,child});
		       else
		         bridges.push_back({child,src});
		   }
		   
		   

		}
	    
	    
	 }
}

void solve(){
	
  
  for(int i=0;i<Size;i++){
      
      vis[i]=false;
      low[i]=-1;
      in[i]=-1;     
  }
  timer=0;  
  vector<int>graph[Size];
  bridges.clear();
  
  int V,E; cin>>V>>E;
  
  for(int i=0;i<E;i++){
     int u,v; cin>>u>>v;
     graph[u].push_back(v);
     graph[v].push_back(u);
  }
  
  dfs(1,-1,graph);
  
  

}


int main(){ 

  open_file();
  fast_io();
  
  
  int t; cin>>t;
  int cnt=1;
  while(t--){
   cout<<"Caso #"<<cnt<<endl; 
   solve();
   if(bridges.empty())cout<<"Sin bloqueos"<<endl;
   else{
      cout<<bridges.size()<<endl;
      sort(bridges.begin(),bridges.end(),cmp);
      for(pair<int,int>p: bridges) {
		  cout<<p.first<<" "<<p.second<<endl;
	  }
   }
   cnt++;
  }
}

 
