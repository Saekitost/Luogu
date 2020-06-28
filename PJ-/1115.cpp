//By EriR @ 2019-02-13 17:52:56
//37ms 0.8MB
//贪心+特判

#include<cstdio>
#define INF 0x3f3f3f3f
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
  return f*x;
}
inline int max(int x,int y){return x>y?x:y;}
int n,t,sum,maxx,minus=-INF;
int main(){
  n=read();
  while(n--){
    t=read();
    sum=sum>0?sum:0;//sum已经小于0了就直接贪心舍去
    minus=max(minus,t);//全是负数时保证有最大负数
    sum+=t;
    maxx=maxx>sum?maxx:sum;
  }
  if(maxx==0&&sum<0) printf("%d",minus);
  else printf("%d",maxx);
  return 0;
}
