#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long int 
#define rep(i, x, y) for (int i = x; i <= y; i++)
void solve()
{
   int n,x;
   cin>>n>>x;
   int price[n+1];  // cost of each books
 
   rep(i,1,n)
   {
      cin>>price[i];
   }
 
   int pages[n+1];
 
   rep(i,1,n)
   {
      cin>>pages[i];
   }
 
 
 
   int dp[n+1][x+1] ;  
 
   for(int i=0;i<=n;i++)
   {
      for(int money=0;money<=x;money++)
      {
         if(money == 0 || i == 0)
                    dp[i][money] = 0;
                else
                {
                    int op1 = (i == 1) ? 0 : dp[i-1][money];
                    int op2 = (money < price[i]) ? 0 : pages[i] + dp[i-1][money - price[i]];
                    dp[i][money] = max(op1,op2);
                }
      }
   }
 
 
   cout<<dp[n][x];
 
 
}
int32_t main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
         solve();
         return 0;
}