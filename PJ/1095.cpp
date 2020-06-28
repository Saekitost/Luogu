//By EriR @ 2019-01-20 17:39:36
//30ms 1.38MB
//DP+贪心

#include<iostream>
#include<cstdio>
using namespace std;
int dp[300005];
int max(int x,int y){return x>y?x:y;}
int main(){
  int MP,S,T,i,ma=0,ans=-1;
  scanf("%d%d%d",&MP,&S,&T);
  for(i=1;i<=T;i++){
    if(MP>=10) MP-=10,dp[i]=dp[i-1]+60;
    else MP+=4,dp[i]=dp[i-1];
  }
  for(i=1;i<=T;i++) dp[i]=max(dp[i],dp[i-1]+17);
  for(i=T;i>=1;i--){
    ma = max(ma,dp[i]);
    if(dp[i]>=S) ans=i;
  }
  ans==-1?printf("No\n%d\n",ma):printf("Yes\n%d\n",ans);
  return 0;
}
