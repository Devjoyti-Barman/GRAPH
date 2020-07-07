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
const int N=100005;

struct dsu{

   vector<int>par;
   
   // Inilization
   void init(int n){
       par.clear();
       par.resize(n);
       for(int i=0;i<n;i++)
        par[i]=i;
   }

   int get(int x){

       if(x==par[x])return x;
       else
        return par[x]=get(par[x]);
   }
   void unite(int x,int y){
       x=get(x);
       y=get(y);
       if(x!=y){
          par[x]=y;
       }
   }

};


void solve(){
    bool cycle=false;
    int n,m;
    cin>>n>>m;
    dsu G;
    G.init(n);
    for(int i=0;i<m;i++){
         int x,y;
         cin>>x>>y;
         x--;y--;
         if(G.get(x)!=G.get(y)){

            G.unite(x,y);
         }else{
            // same component
            // there was a peth from x to y
            //This extra edge will give me a cycle
            cycle=true;
         }
    }

    if(cycle){
        cout<<"cycle exist\n";
    }else{
        cout<<"cycle does not exist\n";
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
