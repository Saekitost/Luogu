//By EriR @ 2019-01-30 11:03:53
//448ms 9.53MB
//线段树模板

#include<cstdio>
typedef long long ll;
const int MAXN = 1000005;
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return f*x;
}
int n,m,op,t1,t2,t3;
ll a[MAXN],ans[MAXN<<2],tag[MAXN<<2];
inline ll ls(ll x){return x<<1;}
inline ll rs(ll x){return x<<1|1;}
inline void push_up(ll p){ans[p]=ans[ls(p)]+ans[rs(p)];}
void build(ll p,ll l,ll r){
  tag[p]=0;//初始化标记
  if(l==r){ans[p]=a[l];return;}//叶子节点是被真实赋值的，左右区间相同则为叶子节点
  ll mid=(l+r)>>1;//二分递归建树
  build(ls(p),l,mid);
  build(rs(p),mid+1,r);
  push_up(p);//由子节点更新父节点，在回溯时更新
}
inline void fun(ll p,ll l,ll r,ll k){//记录当前节点所在区间
  tag[p]+=k;//k为要加的数
  ans[p]+=k*(r-l+1);//区间结果要加元素个数次的k
}
inline void push_down(ll p,ll l,ll r){
  ll mid=(l+r)>>1;//二分向下递归更新
  fun(ls(p),l,mid,tag[p]);
  fun(rs(p),mid+1,r,tag[p]);
  tag[p]=0;//更新完后将tag置零
}
inline void update(ll nl,ll nr,ll l,ll r,ll p,ll k){//nl,nr为需要修改的区间
  if(nl<=l&&r<=nr){//l,r,p为当前节点所存储的区间以及节点的编号
    tag[p]+=k;
    ans[p]+=k*(r-l+1);
    return;
  }
  push_down(p,l,r);//向下传递
  ll mid=(l+r)>>1;
  if(nl<=mid) update(nl,nr,l,mid,ls(p),k);
  if(nr>mid) update(nl,nr,mid+1,r,rs(p),k);
  push_up(p);//回溯更新
}
ll query(ll x,ll y,ll l,ll r,ll p){//x,y表示询问的区间
  ll res=0;
  if(x<=l&&r<=y) return ans[p];
  ll mid=(l+r)>>1;
  push_down(p,l,r);//在分块递归前向下传递
  if(x<=mid) res+= query(x,y,l,mid,ls(p));
  if(y>mid) res+= query(x,y,mid+1,r,rs(p));
  return res;//向上回溯累加
}
int main(){
  n=read(),m=read();
  for(register int i=1;i<=n;i++) a[i]=read();
  build(1,1,n);
  while(m--){
    op=read();
    switch(op){
      case 1:{
        t1=read(),t2=read(),t3=read();
        update(t1,t2,1,n,1,t3);
        break;
      }
      case 2:{
        t1=read(),t2=read();
        printf("%lld\n",query(t1,t2,1,n,1));
        break;
      }
    }
  }
  return 0;
}
