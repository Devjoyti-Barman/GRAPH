/*
https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0

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

void Floyd(vector<vector<int>>&dist,int V){

     int inf=pow(10,7);

     for(int via=0;via<V;via++){

          for(int i=0;i<V;i++){

              for(int j=0;j<V;j++){

                  if(dist[i][via]==inf or dist[via][j]==inf)
                      continue;
                  else
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);                    
              }
          }
     }

     for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){

            if(dist[i][j]==inf)
              cout<<"INF ";
            else
              cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
     }
}

int main()
{

     ios_base::sync_with_stdio(false); 
     cin.tie(nullptr); 
     cout.tie(nullptr);
     
    w(t){ 
            int V;cin>>V;
            vector<vector<int>>dist(V,vector<int>(V));
            for(int i=0;i<V;i++)
               for(int j=0;j<V;j++)
                cin>>dist[i][j];
            Floyd(dist,V);  
           
    }

return 0;  
    
}
