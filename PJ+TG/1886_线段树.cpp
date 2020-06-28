//By EriR @ 2019-02-07 19:55:12
//1106ms 21.43MB(O2)
//线段树+结构体做法

#include<cstdio>
#define inf 0x3f3f3f3f
const int MAXN = 1000005;
namespace io{
  #define in(a) a=read()
  //#define out(a) write(a)
    inline int read(){
    int f=1,x=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return f*x;
  }
  char T[200];
  inline void write(int x){
    if(x==0){putchar('0');return;}
    int tmp=x>0?x:-x;
    if(x<0) putchar('-');
    int cnt=0;
    while(tmp>0){T[cnt++]=tmp%10+'0';tmp/=10;}
    while(cnt) putchar(T[--cnt]);
  }
}
using namespace io;
int a[MAXN],maxn[MAXN<<2],minn[MAXN<<2];
int n,k;
struct res{int ma,mi;}ret;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline void push_up(int p){
  maxn[p]=max(maxn[ls(p)],maxn[rs(p)]);
  minn[p]=min(minn[ls(p)],minn[rs(p)]);
  return;
}
void build(int p,int l,int r){
  if(l==r){maxn[p]=minn[p]=a[l];return;}
  int mid=(l+r)>>1;
  build(ls(p),l,mid);
  build(rs(p),mid+1,r);
  push_up(p);
}
inline res query(int x,int y,int l,int r,int p){
  if(x<=l&&r<=y) return (res){maxn[p],minn[p]};
  int mid=(l+r)>>1;
  int mat=-inf,mit=inf;
  res tmp;
  if(x<=mid){tmp=query(x,y,l,mid,p<<1);mat=max(mat,tmp.ma);mit=min(mit,tmp.mi);}
  if(y>mid){tmp=query(x,y,mid+1,r,p<<1|1);mat=max(mat,tmp.ma);mit=min(mit,tmp.mi);}
  return (res){mat,mit};
}
int main(){
  in(n),in(k);
  for(register int i=1;i<=n;i++) in(a[i]);
  build(1,1,n);
  for(register int i=1;i<=n-k+1;i++){
    ret=query(i,i+k-1,1,n,1);
    write(ret.mi);i!=n-k+1?printf(" "):printf("\n");
    a[i]=ret.ma;
  }
  for(register int i=1;i<=n-k+1;i++){write(a[i]);if(i!=n-k+1) printf(" ");}
  return 0;
}
