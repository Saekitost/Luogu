//By EriR @ 2019-01-15 21:05:35
//15ms 0.75MB
//分治+字符串模拟

#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
  int f=1,x=0;
  char ch;
  do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
  do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
  return f*x;
}
int a[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
void solve(int n){
  if(n==0){printf("0");return;}
  int i,f=0;
  for(i=15;i>=0;i--){
      if(n>=a[i]){
        n -= a[i];
        if(f==0) f=1;
        else printf("+");
        if(i==1) printf("2");
        else{
          printf("2(");
          solve(i);
          printf(")");
      }
    }
  }
}
int main(){
  int n = read();
  solve(n);
  return 0;
}
