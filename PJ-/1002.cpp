//By EriR @ 2019-01-19 09:04:38
//13ms 0.66MB
//DP+模拟

#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int ma[25][25];
ll dp[25][25];
int n,m;
void mark(int a,int b){if(0<=a&&a<=n&&0<=b&&b<=m) ma[a][b]=1;}
int main(){
  int i,j,x,y;
  scanf("%d%d%d%d",&n,&m,&x,&y);
  mark(x,y);
  mark(x+1,y+2);
  mark(x+1,y-2);
  mark(x-1,y+2);
  mark(x-1,y-2);
  mark(x+2,y+1);
  mark(x+2,y-1);
  mark(x-2,y+1);
  mark(x-2,y-1);
  if(ma[0][0]==0) dp[0][0] = 1;
  for(i=0;i<=n;i++) for(j=0;j<=m;j++){
    if(ma[i][j]) continue;
    if(i>0) dp[i][j] += dp[i-1][j];
    if(j>0) dp[i][j] += dp[i][j-1];
  }
  cout<<dp[n][m]<<endl;
  return 0;
}
