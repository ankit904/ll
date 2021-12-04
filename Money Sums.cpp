#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long int 
#define rep(i, x, y) for (int i = x; i <= y; i++)
//const int INF=1e18;
//const int mod=1e9+7;
//   cout<<fixed<<setprecision(7); // 1e-6 
//  number of set bit __builtin_popcount(x) // __builtin_popcountll (long long )
int a[1001];
set<int>res;
int n;
void solve()
{
   cin>>n;
 
   int max_sum = 0;
   rep(i,1,n)
   {
      cin>>a[i];
      max_sum += a[i];
   }
 
   bool dp[n+1][max_sum+1] ;  //dp[i][j] = true if it is possible to make sum j using first i th  term
 
 
   rep(i,0,n)
   {
      rep(j,0,max_sum)
      {
         dp[i][j] = false;
      }
   }
 
 
   dp[0][0] = true;
 
 
   for(int i=1;i<=n;i++)
   {
      for(int sum =0;sum<=max_sum;sum++)
      {
            
         if(dp[i-1][sum]==true || sum==0)
         {
            dp[i][sum] = true;
           
            continue;
         }
 
         if(a[i]>sum)
         {
            dp[i][sum] = false;
            
            continue;
         }
 
         // if(i==2 && sum==2)
         // {
         //    cout<<" ak 1\n";
         // }
         if(dp[i-1][sum-a[i]]==true)
         {
            dp[i][sum] = true;
         }
         else
         {
            dp[i][sum] = false;
         }
 
         // if(i==2 && sum==2)
         // {
         //    // if(dp[i][sum])
         //    // {
         //    //    cout<<" al \n";
         //    // }
         //    cout<<dp[i][sum]<<"\n";
         // }
 
      }
   }
 
 
   set<int>st;
 
   rep(i,1,n)
   {
      rep(j,1,max_sum)
      {
         if(dp[i][j]==true)
         {
            st.insert(j);
         }
      }
   }
 
   cout<<st.size()<<"\n";
 
   for(auto ele:st)
   {
      cout<<ele<<" ";
   }
 
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