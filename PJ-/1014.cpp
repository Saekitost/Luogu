//By EriR @ 2019-01-15 21:06:26
//12ms 0.79MB
//模拟+枚举

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
int main(){
  int fin = read();
  int row,res,cnt=0;
  for(row=1;cnt<fin;row++) cnt+=row;
  row--;cnt-=row;
  res = fin - cnt;
  if(row%2==0) printf("%d/%d",res,row+1-res);
  else printf("%d/%d",row+1-res,res);
  return 0;
}
