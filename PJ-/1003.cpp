//By EriR @ 2019-01-25 21:31:44
//31ms 0.79MB
//数学+模拟

#include<cstdio>
#include<cstring>
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return f*x;
}
int n,x,y;
int a[10005][5];
int main(){
  n=read();
  for(int i=1;i<=n;i++){
    a[i][1]=read(),a[i][2]=read(),a[i][3]=read(),a[i][4]=read();
    a[i][3]+=a[i][1];a[i][4]+=a[i][2];
  }
  x=read(),y=read();
  for(int i=n;i>0;i--) if(a[i][1]<=x&&a[i][2]<=y&&a[i][3]>=x&&a[i][4]>=y){
    printf("%d",i);//从最后一个地毯开始找，一旦有解就退出
    return 0;
  }
  printf("-1");
  return 0;
}
