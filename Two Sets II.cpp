#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long int 
#define rep(i, x, y) for (int i = x; i <= y; i++)
//const int INF=1e18;
const int mod=1e9+7;
//   cout<<fixed<<setprecision(7); // 1e-6 
//  number of set bit __builtin_popcount(x) // __builtin_popcountll (long long )
void solve()
{
   int n;
   cin>>n;
   int sum = (n*(n+1))/2;
   if(sum%2)
   {
      cout<<"0";
      return;
   }
 
   sum/=2;
 
   int dp[n+1][sum+1];  //   dp[i][j] =>  no of ways of making sum j by using the fitst ith element 
 
   dp[0][0] =1;
 
   for(int i=0;i<n;i++)
   {
      for(int sm=0;sm<=sum;sm++)
      {
         if(sm==0)
         {
            dp[i][sm] =1;
            continue;
         }
         if(i==0 && sm>0)
         {
            dp[i][sm] =0;
            continue;
         }
         int opt1,opt2;
         
         // include ith
         if(sm>=i && i-1>=0)
         {
            opt1 = dp[i-1][sm-i];
         }
         else{
            opt1 = 0;
         }
 
         // not include 
 
         if(i-1>=0)
         {
            opt2 = dp[i-1][sm];
         }
         else{
            opt2 = 0;
         }
 
         dp[i][sm] = (opt1%mod + opt2%mod)%mod;
 
      }
   }
 
   cout<<(dp[n-1][sum]);
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