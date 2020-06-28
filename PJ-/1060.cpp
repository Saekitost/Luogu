//By EriR @ 2019-01-20 17:38:45
//54ms 3.41MB
//DP(背包)

#include<iostream>
#include<cstdio>
using namespace std;
int w[30],v[30];
int dp[30][30005];
int n,m;
int max(int x,int y){return x>y?x:y;}
int main(){
  int i,j,ans=0;
  scanf("%d%d",&n,&m);
  for(i=1;i<=m;i++){
    scanf("%d%d",&v[i],&w[i]);
    w[i]*=v[i];
  }
  for(i=1;i<=m;i++) for(j=1;j<=n;j++){
    dp[i][j] = dp[i-1][j];
    if(j-v[i]>=0) dp[i][j] = max(dp[i][j],dp[i-1][j-v[i]]+w[i]);
  }
  for(i=1;i<=n;i++) ans = max(ans,dp[m][i]);
  printf("%d\n",ans);
  return 0;
}
