//By EriR @ 2019-01-31 12:27:10
//489ms 2.54MB
//树状数组模板

#include<cstdio>
typedef long long ll;
namespace io{
    inline int read(){
    int f=1,x=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return f*x;
  }
  char T[200];
  inline void write(ll x){
    if(x==0){putchar('0');return;}
    ll tmp=x>0?x:-x;
    if(x<0) putchar('-');
    int cnt=0;
    while(tmp>0){T[cnt++]=tmp%10+'0';tmp/=10;}
    while(cnt) putchar(T[--cnt]);
    puts("");
  }
}
using namespace io;
const int MAXN = 500005;
int N,M,tmp,op,t1,t2;
int tree[MAXN];
//inline int max(int x,int y){return x>y?x:y;} //查询区间的前后大小关系不影响时不需要
//inline int min(int x,int y){return x<y?x:y;}
inline int lowbit(int x){return x&(-x);}//返回的数是 2^k k表示x在二进制下从后往前第一个1的位置-1
inline void build(){//根据所给数据构造数组
  for(register int i=1;i<=N;i++){
    tmp=read();//直接读入
    for(register int j=i;j<=N;j+=lowbit(j)) tree[j]+=tmp;
  }//每次读入时便将需要传递的数字向后传递
}
void update(int x,int k){while(x<=N){tree[x]+=k;x+=lowbit(x);}}//单点修改 由前往后传递
ll query(int x){//向下累加
  ll ans=0;
  while(x){ans+=tree[x];x-=lowbit(x);}
  return ans;
}
inline ll check(int x,int y){return query(y)-query(x-1);}//查询区间和用两点数据差表示
int main(){
  N=read(),M=read();
  build();
  while(M--){
    op=read();
    switch(op){
      case 1:{t1=read(),t2=read();update(t1,t2);break;}
      case 2:{
        t1=read(),t2=read();
        write(check(t1,t2));
        break;
      }
    }
  }
  return 0;
}
