/*
https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

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


void adj(vector<ipair>path[],int u,int v,int w){
    
     path[u].push_back(mk(v,w));
     path[v].push_back(mk(u,w));
}


void prims(vector<pair<int,int> > path[],int V){
        priority_queue< ipair, vector <ipair> , greater<ipair> >Q;
        vector<int> key(V,INT_MAX);
        
        vector<bool> MST(V, false); 
         
        int src=0;
        Q.push(make_pair(0,src));
        key[src]=0;
        
        
        while (!Q.empty())
        {
            int u= Q.top().second;
            Q.pop();
            MST[u]=true;
             
          
            for(auto x : path[u])
            {
                 int v=x.first;
                 int weight=x.second;

            
               if(MST[v] == false && key[v]>weight){
                   key[v]=weight;
                   Q.push(make_pair(key[v], v));
                   
              }
                                     
            }
    
        }
       ll sum=0;
       for(int x:key)sum+=x;
        cout<<sum<<endl;
}




int main()
{

	   ios_base::sync_with_stdio(false); 
	   cin.tie(nullptr); 
	   cout.tie(nullptr);
    
    int V,E;cin>>V>>E;
    vector<ipair>A[V];
    while(E--){
		int a,b,w;
		cin>>a>>b>>w;
		adj(A,a-1,b-1,w);
	}

    prims(A,V);
    return 0;
    
}

