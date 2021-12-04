#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long int 
#define rep(i, x, y) for (int i = x; i <= y; i++)
//const int INF=1e18;
const int mod=1e9+7;
//   cout<<fixed<<setprecision(7); // 1e-6 
//  number of set bit __builtin_popcount(x) // __builtin_popcountll (long long )
const int N = 1e6+1;
int dp[N+1][2];         //  dp[i][2] = dp[i][0](the i yh tile was seperated) + dp[i][1] (i th tile was attached)
 
void fun()
{
 
   dp[1][0] = 1;
   dp[1][1] = 1;
 
   // dp[i][0]  =   
   for(int i=2;i<=N;i++)
   {
      dp[i-1][0]%=mod;
      dp[i-1][1]%=mod;   // (4*(dp[i-1][0])) + dp[i-1][1]
 
      dp[i][0] =   ((4*(dp[i-1][0]))%mod +  (dp[i-1][1])%mod)%mod; // last tile separated
 
 
      //     (2*(dp[i-1][1])) +  dp[i-1][0]
      
      dp[i][1] =  ((2*(dp[i-1][1]))%mod +  dp[i-1][0]%mod)%mod; // last tile attached 
 
      dp[i][0] %=mod;
      dp[i][1] %=mod;
   }
}
void solve()
{
   int n;
   cin>>n;
 
   cout<<(dp[n][0]%mod + dp[n][1]%mod)%mod<<"\n"; 
}
int32_t main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
      int t;
      cin>>t;
      fun();
      while(t--)
      {
         solve();
      }
   return 0;
}