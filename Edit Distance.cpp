#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long int 
#define rep(i, x, y) for (int i = x; i <= y; i++)
//const int INF=1e18;
//const int mod=1e9+7;
//   cout<<fixed<<setprecision(7); // 1e-6 
//  number of set bit __builtin_popcount(x) // __builtin_popcountll (long long )
 
int dp[5001][5001];  //    dp[i][j] =>   edit distance of s1(from i to s1.size()) with s2 (from j to s2.size())
int fun(int i,int j,string &s1,string &s2)
{
   if(i==s1.size() || j==s2.size())
   {
      return  ((s1.size()-i) + (s2.size()-j));
   }
 
   if(dp[i][j]!=-1)
   {
      return dp[i][j];
   }
   
   int ans;
   if(s1[i]==s2[j])
   {
      ans = fun(i+1,j+1,s1,s2);
   }
   else
   {
      int opt1,opt2,opt3;
 
      // remove
      opt1 = 1+ fun(i+1,j,s1,s2);
 
      // replace
      opt2 = 1+ fun(i+1,j+1,s1,s2);
 
      //add
      opt3 = 1 + fun(i,j+1,s1,s2);
 
      ans = min(opt1,min(opt2,opt3));
   }
 
   return dp[i][j] = ans;
 
}
void solve()
{
 
   memset(dp,-1,sizeof(dp));
   string s1,s2;
   cin>>s1>>s2;
 
   cout<<fun(0,0,s1,s2);
 
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