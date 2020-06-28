//By EriR @ 2019-01-19 09:06:51
//14ms 0.9MB
//DP

#include<cstdio>
int w[35],dp[20005];
int max(int x,int y){return x>y?x:y;}
int main(){
  int V,N,i,k,t,ans=0;
  scanf("%d%d",&V,&N);
  for(i=1;i<=N;i++) scanf("%d",&w[i]);
  for(k=1;k<=N;k++) for(t=V;t>=1;t--) if(t-w[k]>=0) dp[t] = max(dp[t],dp[t-w[k]]+w[k]);
  for(i=1;i<=V;i++) ans = max(ans,dp[i]);
  printf("%d\n",V-ans);
  return 0;
}
