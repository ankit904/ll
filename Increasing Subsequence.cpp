#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long int 
#define rep(i, x, y) for (int i = x; i <= y; i++)
//const int INF=1e18;
//const int mod=1e9+7;
//   cout<<fixed<<setprecision(7); // 1e-6 
//  number of set bit __builtin_popcount(x) // __builtin_popcountll (long long )
 
map<int,int>candidates;   //   value aur usko include krke best advantage kitne number ka mil rha ha 
int a[200003];
int get_best_condidate(int val)
{
   auto it = candidates.lower_bound(val);  //  greater or equal value then val
 
   if(it==candidates.begin())
   {
      return 0;
   }
 
   it--;
 
   return  it->second;  // best value 
}
 
 
void insert(int val,int adv)  // adv  -> dp[val] which include val
{
   if(candidates[val]>=adv)
   {
      return;
   }
 
   candidates[val] = adv;
 
   //   if there is a privious one that has value greater than val but give less or equal advantage 
 
   //  we need to deleate that 
   auto it = candidates.find(val);
   
   it++;
 
   while(it!=candidates.end() && it->second <= adv)
   {
      auto temp = it;
      it ++;
      candidates.erase(temp);
   }
 
}
 
void solve()
{
   int n;
   cin>>n;
   rep(i,1,n)
   {
      cin>>a[i];
   }
 
 
   int dp[n+1];  //  dp[i] =>  length of max increasing subsiquence which end at ith element 
 
   for(int i=1;i<=n;i++)
   {
      dp[i] =1;
 
      dp[i] += get_best_condidate(a[i]);
 
      insert(a[i],dp[i]);
   }
 
 
   cout<<*max_element(dp+1,dp+n+1);
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