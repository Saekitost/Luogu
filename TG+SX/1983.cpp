//By EriR @ 2019-01-29 18:43:20
//658ms 5.41MB(O2)
//以下为模拟化暴搜 正解为图+toposort

#include<cstdio>
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return f*x;
}
int max(int x,int y){return x>y?x:y;}
int n,m,a[1000],s[1000],f[1000][1000];//车站分级/第i车经过的车站数/第i车停靠的第j个车站
bool pas[1000][1000];
int main(){
  n=read();m=read();
  for(register int k=0;k<n;++k) a[k]=1;//初始化车站等级为1
  for(register int k=0;k<m;++k){
    s[k]=read();
    for(register int i=0;i<s[k];++i)f[k][i]=read()-1,pas[k][f[k][i]]=1;
  }
  while(1){
    bool flag=0;//是否有车站等级改变
    for(register int k=0;k<m;++k){
    int maxl=0;
    for(register int i=f[k][0];i<=f[k][s[k]-1];++i) if(!pas[k][i])maxl=max(maxl,a[i]);
    maxl++;//经过的车站等级至少比未经过的大1
    for(register int i=0;i<s[k];++i) if(a[f[k][i]]<maxl)a[f[k][i]]=maxl,flag=1;
  }
  if(!flag) break;//没有车站等级发生改变则已经全部分级
}
  int maxl=0;
  for(register int k=0;k<n;++k) maxl=max(maxl,a[k]);
  printf("%d",maxl);
  return 0;
}
