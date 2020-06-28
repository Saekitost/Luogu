//By EriR @ 2019-01-30 19:56:59
//392ms 0.77MB(02)
//dfs+回溯搜索

#include<cstdio>
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return f*x;
}
int n,cnt,p[15],f[3][30];//f[0]列,f[1]/f[2]为对角线
void out(){cnt++;if(cnt>3)return;for(int i=1;i<=n;i++) i!=n?printf("%d ",p[i]):printf("%d\n",p[i]);}
void search(int x){//x表示行
  if(x>n) out();
  for(int i=1;i<=n;i++){
    if(!f[0][i]&&!f[1][x+i]&&!f[2][x-i+n]){//i表示列
      p[x]=i;
      f[0][i]=f[1][x+i]=f[2][x-i+n]=1;//+n防止负数干扰
      search(x+1);//搜索下一行
      f[0][i]=f[1][x+i]=f[2][x-i+n]=0;//回溯
    }
  }
}
int main(){
  n=read();
  search(1);//从第一行开始d
  printf("%d",cnt);//补结果数
  return 0;
}
