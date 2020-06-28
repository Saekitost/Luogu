//By EriR @ 2019-01-30 12:14:47
//47ms 0.88MB
//模拟+二分答案

#include<cstdio>
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return f*x;
}
int L,N,M,mid,ans,a[50005];
bool check(int x){
  int cnt=0,p=0,pn=0;//由pn跳向p，模拟差分的效果
  while(p<N+1){
    p++;
    if(a[p]-a[pn]<x) cnt++;
    else pn=p;
  }
  if(cnt>M) return false;
  else return true;
}
int main(){
  L=read(),N=read(),M=read();
  for(register int i=1;i<=N;i++) a[i]=read();
  a[N+1]=L;
  int l=1,r=L;
  while(l<=r){
    mid=(l+r)>>1;
    if(check(mid)){ans=mid;l=mid+1;}//不断更新结果
    else r=mid-1;
  }
  printf("%d",ans);//最后一定是最优解
  return 0;
}
