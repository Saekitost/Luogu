//By EriR @ 2019-01-21 20:08:20
//247ms 5.11MB
//图的遍历(STL+dfs)

#include<cstdio>
#include<vector>
#define MAXL 100010
using namespace std;
int N,M,visit[MAXL];
vector<int> a[MAXL];
void dfs(int x,int y){
  if(visit[x]) return;
  visit[x] = y;
  for(int i=0;i<a[x].size();i++) dfs(a[x][i],y);
}
int main(){
  int u,v,i;
  scanf("%d%d",&N,&M);
  for(i=1;i<=M;i++){
    scanf("%d%d",&u,&v);
    a[v].push_back(u);
  }
  for(i=N;i>0;i--) dfs(i,i);
  for(i=1;i<=N;i++) i!=N?printf("%d ",visit[i]):printf("%d",visit[i]);
  return 0;
}
