//By EriR @ 2019-02-28 21:20:20
//23ms 0.79MB
//数论(ExGcd/同余)

#include<cstdio>
int t,x,y,a,b;
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
  return f*x;
}
void ExGkd(int a,int b){
  if(b==0){x=1,y=0;return;}
  ExGkd(b,a%b);
  t=x;
  x=y;
  y=t-a/b*y;
  return;
}
int main(){
  a=read(),b=read();
  ExGkd(a,b);
  printf("%d",(x+b)%b);
  return 0;
}
