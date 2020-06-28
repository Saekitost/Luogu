//By EriR @ 2019-01-15 21:04:44
//32ms 0.78MB
//并查集

#include<iostream>
#include<cstdio>
using namespace std;
const int N = 5000+10;
int f[N],n,m,p;
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int merge(int x,int y){
  int xx=find(x),yy=find(y);
  f[xx]=yy;
}
inline int read(){
  int f=1,x=0;
  char ch;
  do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
  do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
  return f*x;
}
int main(){
  n=read(),m=read(),p=read();
  for(int i=1;i<=n;i++) f[i]=i;
  while(m--){
    int t1=read(),t2=read();
    merge(t1,t2);
  }
  while(p--){
    int t1=read(),t2=read();
    int xx=find(t1),yy=find(t2);
    xx==yy?printf("Yes\n"):printf("No\n");
  }
  return 0;
}
