//By EriR @ 2019-02-10 19:11:09
//719ms 16.15MB(O2)
//单调队列/线段树/zkw线段树/ST表/RMQ+滚动数组

#include<cstdio>
#define INF 0x3f3f3f3f
const int MAXN = 2000005;
namespace io{
  #define in(a) a=read()
  #define out(a) write(a)
  inline int read(){
    int f=1,x=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
    return f*x;
  }
  char T[50];
  inline void write(int x){
    if(x==0){putchar('0');return;}
    int tmp=x>0?x:-x;
    if(x<0) putchar('-');
    int cnt=0;
    while(tmp>0){T[cnt++]=tmp%10+'0';tmp/=10;}
    while(cnt) putchar(T[--cnt]);
    puts("");
  }
}
using namespace io;
int N,M,tree[MAXN<<1];
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
int main(){
  in(N),in(M);
  for(register int i=1;i<=N;i++) in(tree[N+i]);
  tree[N<<1|1]=INF;
  for(register int i=N;i>0;i--) tree[i]=min(tree[i<<1],tree[i<<1|1]);//建树
  puts("0");//第一个肯定是0
  for(register int i=2;i<=N;i++){
    int l=max(N,N-M+i-1),r=N+i;//zkw开区间查询
    int ans=INF;
    while(l^r^1){//zkw线段树查询
      if(~l&1) ans=min(tree[l^1],ans);
      if(r&1) ans=min(tree[r^1],ans);
      l>>=1,r>>=1;
    }
    out(ans);
  }
  return 0;
}
