//By EriR @ 2019-01-21 20:09:39
//1544ns 9.22MB
//DP+二分+单调队列(deque实现)

#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;
#define INF 233333333333333//把不能到的点存足够大的负值，不然会哇
typedef long long ll;
ll n,d,k;
int x[500005],s[500005];
ll dp[500005];
int cr;
deque <int> q;
ll max(ll a,ll b){return a>b?a:b;}
void read(){
  int i;
  scanf("%lld%lld%lld",&n,&d,&k);
  for(i=1;i<=n;i++) scanf("%d%d",&x[i],&s[i]);
}
ll check_max(ll l,ll r){//deque实现单调队列
  while(cr<=n&&x[cr]<=r){
    while(!q.empty()&&dp[q.back()]<=dp[cr]) q.pop_back();
    q.push_back(cr);
    cr++;
  }
  while(!q.empty()&&x[q.front()]<l) q.pop_front();
  if(!q.empty()) return dp[q.front()];
  if(l<=0&&0<=r) return 0;
  return -INF;
}
ll DP(int g){
  int i,l,r;
  ll ma = -INF;
  memset(dp,0,sizeof(dp));
  q.clear();cr=0;
  for(i=1;i<=n;i++){
    l=x[i]-d-g;
    r=x[i]-d+g;
    if(r>=x[i]) r=x[i]-1;
    dp[i]=check_max(l,r)+s[i];
    ma=max(ma,dp[i]);
  }
  return ma;
}
int check(int g){
  if(DP(g)>=k) return true;
  return false;
}
void bsearch(){//二分答案
  int l=0,r=1000000005,mid;
  while(l!=r){
    mid=(l+r)>>1;
    if(check(mid)) r=mid;
    else l=mid+1;
  }
  if(check(l)) printf("%d\n",l);
  else printf("-1\n");
}
int main(){
  read();
  bsearch();
  return 0;
}
