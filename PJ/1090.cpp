//By EriR @ 2019-01-15 21:07:43
//117ms 0.98MB
//优先队列(STL)

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
struct rebuild{//运算符重载
  ll v;
  bool operator <(const rebuild &x)const{return v>x.v;}
};
rebuild make_struct(ll v){
  rebuild tmp;tmp.v=v;return tmp;
}
inline int read(){
  int f=1,x=0;
  char ch;
  do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
  do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
  return f*x;
}
priority_queue<rebuild> q;
int n,m,sum,ans;
int main(){
  n = read();
  sum = n;
  for(int i=1;i<=n;i++){
    m = read();
    q.push(make_struct(m));
  }
  while(sum>1){
    int x = q.top().v;
    q.pop();
    int y = q.top().v;
    q.pop();
    ans += x+y;
    q.push(make_struct(x+y));
    sum--;
  }
  printf("%d\n",ans);
  return 0;
}
