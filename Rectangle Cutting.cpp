#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long int 
#define rep(i, x, y) for (int i = x; i <= y; i++)
//const int INF=1e18;
//const int mod=1e9+7;
//   cout<<fixed<<setprecision(7); // 1e-6 
//  number of set bit __builtin_popcount(x) // __builtin_popcountll (long long )
// const int N = 1e5+1;
 
int dp[5001][5001];
 
int fun(int i,int j)
{
   if(i==j)
   {
      return 0;
   }
 
   if(dp[i][j]!=-1)
   {
      return dp[i][j];
   }
 
   //vertical
   int ans = INT_MAX;
 
   for(int b=1;b<=j-1;b++)
   {
      ans = min(ans,(1+fun(i,b) + fun(i,j-b)));
   }
 
   // horizontal
 
   for(int a =1;a<=i-1;a++)
   {
      ans = min(ans,(1+fun(a,j) + fun(i-a,j)));
   }
 
   return dp[i][j] = ans;
 
}
void solve()
{
 
   memset(dp,-1,sizeof(dp));
 
   int a,b;
   cin>>a>>b;
 
 
  //  dp[i][j] => min no. of move to get a square from (i*j)
 
  cout<<fun(a,b);
   
}
int32_t main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
      // int t;
      // cin>>t;
      // while(t--)
      // {
         solve();
      // }
   return 0;
}