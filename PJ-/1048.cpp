//By EriR @ 2019-01-19 09:05:37
//32ms 1.06MB
//DP

#include<cstdio>
int c[105],w[105];
int dp[105][1005];
int max(int a,int b){return a>b?a:b;}
int main(){
  int T,M,k,t,i,ans=0;
  scanf("%d%d",&T,&M);
  for(i=1;i<=M;i++) scanf("%d%d",&c[i],&w[i]);
  for(k=1;k<=M;k++) for(t=1;t<=T;t++){
    dp[k][t] = dp[k-1][t];
    if(t-c[k]>=0) dp[k][t] = max(dp[k][t],dp[k-1][t-c[k]]+w[k]);
  }
  for(t=1;t<=T;t++) ans = max(ans,dp[M][t]);
  printf("%d\n",ans);
  return 0;
}
