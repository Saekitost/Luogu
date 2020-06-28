//By EriR @ 2019-01-26 15:08:18
//133ms 2.02MB
//并查集+贪心

#include<cstdio>
#include <algorithm>
using namespace std;
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return f*x;
}
int N,M;
int a[20005],b[20005];
struct data{int x,y,z;}f[100005];
bool cmp(data a,data b){return a.z>b.z;}
int find(int x){return a[x]==x?x:a[x]=find(a[x]);}
void merge(int x,int y){x=find(a[x]),y=find(a[y]);a[x]=y;}
bool check(int x,int y){x=find(x),y=find(y);return x==y;}
int main(){
  N=read(),M=read();
  for(register int i=1;i<=N;i++) a[i]=i;
  for(register int i=1;i<=M;i++) f[i].x=read(),f[i].y=read(),f[i].z=read();
  sort(f+1,f+M+1,cmp);
  for(register int i=1;i<=M+1;i++){//上界设为M+1，则循环到M+1的时候会输出0
    if(check(f[i].x,f[i].y)){printf("%d",f[i].z);break;}//如果两个罪犯已经在同一监狱就输出并退出
    else{//↓标记敌人                         ↓将敌人的敌人合并
      if(!b[f[i].x]) b[f[i].x]=f[i].y; else merge(b[f[i].x],f[i].y);
      if(!b[f[i].y]) b[f[i].y]=f[i].x; else merge(b[f[i].y],f[i].x);
    }
  }
  return 0;
}
