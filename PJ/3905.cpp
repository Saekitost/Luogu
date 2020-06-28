//By EriR @ 2019-01-21 20:10:51
//64ms 0.88MB
//图论(最短路)+Floyd

#include<cstdio>
#include<cstring>
int dis[105][105],res[105][105];
int min(int x,int y){return x>y?y:x;}
void floyd(int n){
  int i,j,k;
  for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        res[i][j]=min(res[i][j],res[i][k]+res[k][j]);
}
int main(){
  int i,t1,t2,n,m,k;
  memset(res,0x3f,sizeof(res));
  scanf("%d%d",&n,&m);
  for(i=1;i<=m;i++){
    scanf("%d%d",&t1,&t2);
    scanf("%d",&dis[t1][t2]);
    dis[t2][t1]=dis[t1][t2];
    res[t2][t1]=res[t1][t2]=0;//核心在于把被毁掉的道路权值设为0即可跑最短路
  }
  scanf("%d",&k);
  for(i=1;i<=k;i++){
    scanf("%d%d",&t1,&t2);
    res[t1][t2]=res[t2][t1]=dis[t1][t2];
  }
  floyd(n);
  scanf("%d%d",&t1,&t2);
  printf("%d",res[t1][t2]);
  return 0;
}
