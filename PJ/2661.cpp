//By EriR @ 2019-01-28 08:04:28
//44ms 2.18MB
//图论(并查集)

#include<cstdio>
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return f*x;
}
int n,res,f[200005],dis[200005];
int min(int x,int y){return x<y?x:y;}
int find(int x){
  if(f[x]!=x){//查找时沿途更新祖先节点和路径长
    int tmp = f[x];//记录父节点(注意此处是局部变量，否则会在递归中被更新)
    f[x]=find(f[x]);//更新祖先节点
    dis[x]+=dis[tmp];//更新路径长(原来连在父节点上)
  }
  return f[x];
}
void check(int a){
  int b = read();
  int x=find(a),y=find(b);//查找祖先节点
  if(x!=y){f[x]=y;dis[a]=dis[b]+1;}//如果不相连则更新父节点和路径长
  else res=min(res,dis[a]+dis[b]+1);//已连接则更新最小环长度
}
int main(){
  n=read();
  res=0x3f3f3f3f;
  for(register int i=1;i<=n;i++) f[i]=i;//初始化每个点，使其指向自己
  for(register int i=1;i<=n;i++) check(i);//循环检查两个点是否相连
  printf("%d",res);//最小环
  return 0;
}
