/*
   This is only work for tree like graph

*/

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

const int N=10005;
vector<int>gr[N];

int tin[N],tout[N],timer;

void euler_tour_1(int cur,int par){
  cout<<cur<<" ";
  for(auto x:gr[cur]){
      if(x!=par){
        euler_tour_1(x,cur);
        cout<<cur<<" ";
      }
  }
  return;
}

void euler_tour_2(int cur,int par){
  //cout<<cur<<" ";
  //enter a node Here timer will start from 1
  tin[cur]=timer++;
  for(auto x:gr[cur]){
      if(x!=par){
        euler_tour_2(x,cur);
      }
  }
  //leave a node
  tout[cur]=timer++;
  //cout<<cur<<" ";
  return;
}

void euler_tour_3(int cur,int par){
  //cout<<cur<<" ";
  // enter a node
  tin[cur]=++timer;
  for(auto x:gr[cur]){
      if(x!=par){
        euler_tour_3(x,cur);
      }
  }
  // leave a node
  tout[cur]=timer;
  return;
}

bool is_ancestor(int x,int y){
    return tin[x]<=tin[y] and tout[x]>=tout[y];
}

void solve(){
   int n;
   cin>>n;

   for(int i=0;i<n-1;i++){
      int x,y;
      cin>>x>>y;
      gr[x].pb(y);
      gr[y].pb(x);
   }
   timer=0;
   //euler_tour_1(1,0);
   //euler_tour_2(1,0); // here timer will start from 1;
   euler_tour_3(1,0);
   
  /*
   for(int i=1;i<=n;i++){
      cout<<i<<" "<<tin[i]<<" "<<tout[i]<<"\n";
   }
   */
  if(is_ancestor(3,7))
     cout<<"YES\n";
   else
    cout<<"NO\n";
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
