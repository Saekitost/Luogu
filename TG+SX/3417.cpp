//By EriR @ 2019-01-28 21:25:29
//345ms 20.3MB(O2)
//枚举+前缀和优化

#include<cstdio>
#include<cstring>
namespace io{
  //#define in(a) a=read()
  //#define out(a) write(a)
  short inline read(){
    short f=1,x=0;char c=getchar();
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
int n,cnt;
short k[1005],ans[5]={0,1,3,3,1};
char a[5],*ch[1005];
struct data{
  short fir[10];
  void init(){memset(fir,0,sizeof(fir));}
}*pos[1005],tmp;
bool check(int x){
  int p,f;
  for(int i=1;i<=n;i++){
    for(p=1,f=0;p<=x;p++) if(pos[i][f].fir[a[p]]) f=pos[i][f].fir[a[p]]; else break;
    if(p<=x) return false;
  }
  return true;
}
void dfs(int x){
  for(char i=0;i<=9;i++) if(i!=a[x-1]){
    a[x]=i;
    if(check(x)) cnt+=ans[x];
    if(x<4) dfs(x+1);
  }
}
//使用前缀和的思想，维护一个十元组,pos[𝑖][𝑗][𝑘](𝑘=0−9)
//表示第𝑖个动作的第𝑗位向后的最近一个数字𝑘的位置
int main(){
  n=read();
  for(int i=1;i<=n;i++){
    k[i]=read();
    ch[i]=new char[k[i]+2];
    pos[i]=new data[k[i]+2];
    scanf("%s",ch[i]+1);
    tmp.init();
    for(int j=k[i];j>=0;j--){
      pos[i][j]=tmp;
      if(j) tmp.fir[ch[i][j]-'0']=j;
    }
  }
  a[0]=-1;
  dfs(1);
  write(cnt);
  return 0;
}
