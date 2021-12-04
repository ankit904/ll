#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long int 
#define rep(i, x, y) for (int i = x; i <= y; i++)
//const int INF=1e18;
//const int mod=1e9+7;
//   cout<<fixed<<setprecision(7); // 1e-6 
//  number of set bit __builtin_popcount(x) // __builtin_popcountll (long long )
 
struct input {
   int a,b,p;
};
 
bool comp(input a,input b)
{
   return  a.b<b.b;
}
 
int binary_serch(input arr[],int idx)
{
   int lo = 1,hi = idx,mid;
 
   while(hi-lo>1)
   {
      mid = lo + (hi-lo)/2;
 
      if(arr[mid].b < arr[idx].a)
      {
         lo = mid;
      }
      else
      {
         hi = mid-1;
      }
 
   }
 
   if(arr[hi].b  < arr[idx].a)
   {
      return hi;
   }
   else if(arr[lo].b  < arr[idx].a)
   {
      return lo;
   }
   else{
      return -1;
   }
}
void solve()
{
   int n;
   cin>>n;
 
   input arr[n+1];
 
   rep(i,1,n)
   {
      cin>>arr[i].a>>arr[i].b>>arr[i].p;
   }
 
 
   sort(arr+1,arr+n+1,comp);
 
   int dp[n+1];   //  dp[i] => max till ith position 
 
 
   dp[1] = arr[1].p;
 
   rep(i,2,n)
   {
      int inc = arr[i].p;   // inclue  ith element 
 
      if(binary_serch(arr,i)!=-1)
      {
        int idx= binary_serch(arr,i);
        inc += dp[idx];
      }
 
      int exc   = dp[i-1];  //  not include this 
 
      dp[i] = max(inc,exc);
 
   }
 
   cout<<dp[n];
 
}
int32_t main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
     
         solve();
      
   return 0;
}