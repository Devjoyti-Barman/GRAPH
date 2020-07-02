/*
https://www.spoj.com/problems/PESADA04/

*/

#include<stdio.h>
#include<math.h>
#define inf 999999999

int dp[4100][12];
int dist[13][13];

int tsp_problem(int mask,int pos,int vis,int n){
     
     if(mask==vis){
        return dist[pos][0];
     }

    if(dp[mask][pos]!=-1)
      return dp[mask][pos];

    
     int ans=inf;
     // Got to every unvisited city
     for(int city=0;city<n;city++){

         if( (mask&(1<<city))==0){
             
             int newans=dist[pos][city]+tsp_problem(mask|(1<<city),city,vis,n);
             
             if(newans<ans)
             ans=newans;
             
         }
     }
     return dp[mask][pos]=ans;
} 


int main()
{

     int t;scanf("%d",&t);
     while(t--){
                 
        int n;scanf("%d",&n);
        n=n+1; 
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++){
              if(i==j)continue;
              scanf("%d",&dist[i][j]);
          }
        
        int vis=(1<<n)-1;
        
        for(int i=0;i<=vis;i++)
           for(int j=0;j<=n;j++)
            dp[i][j]=-1;
        
        
          printf("%d\n",tsp_problem(1,0,vis,n));
     }
  return 0;
}
     

