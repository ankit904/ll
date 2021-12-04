#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define rep(i, x, y) for (int i = x; i <= y; i++)
//const int INF=1e18;
const int mod=1e9+7;
//   cout<<fixed<<setprecision(7); // 1e-6 
//  number of set bit __builtin_popcount(x) // __builtin_popcountll (long long )
void solve()
{
   int n,m;
   cin>>n>>m;
 
   int a[n+1];
   rep(i,1,n)
   {
      cin>>a[i];
   }
 
   //  dp[i][j]  =>  no of valid array of size i having last element j 
 
   int dp[n+2][m+2];
   memset(dp,0,sizeof(dp));
 
 
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         if(i==1)
         {
            if(a[i]==0 || a[i]==j)
            {
               dp[i][j] =1;
            }
            else{
               dp[i][j] =0;
            }
         }
         else
         {
            if(a[i]==0 || a[i]==j)
            {
               dp[i][j] = ((dp[i-1][j] %mod+ dp[i-1][j+1]%mod)%mod+ (dp[i-1][j-1])%mod)%mod;
            }
            else
            {
               dp[i][j] =0;
            }
         }
      }  
   }
 
   int ans =0;
 
   rep(i,1,m)
   {
      ans  = (ans + dp[n][i])%mod;
   }
 
   cout<<ans;
 
} 
int32_t main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
         solve();
   return 0;
}