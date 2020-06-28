//By EriR @ 2019-01-28 15:59:27
//886ms 0.91MB
//真·数学思维题(枚举+剪枝)

#include<cstdio>
#include<cmath>
typedef long long ll;
inline ll read(){
  ll f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return f*x;
}
int n,j,num[10000];
ll cnt,tmp;
bool yz(){//判断是否回文
  for(int i=1;i<=cnt/2;i++) if(num[i]!=num[cnt-i+1]) return false;
  return true;
}
bool solve(ll x,ll y){//把两个数分解
  ll t=x;cnt=0;
  while(t>0){
    cnt++;
    num[cnt]=t%y;
    t/=y;
  }
  return yz();
}
//用到的思想原理：当这个进制数比较大之后，超过√a[i]时，根据题意可以发现
//转换到这个进制之后，新的数只会是个两位数；假设两个相同的数都为 t
//那么 t*x(进制)+t=a[i]化简可得x=a[i]/j-1
//所以x<√a[i]直接枚举，x>√a[i]时如果t是a[i]的一个因数则x=a[i]/j-1为答案
int main(){
  n=read();
  for(int i=1;i<=n;i++){
    bool f=false;
    tmp=read();
    j=1;
    do{
      j++;
      if(solve(tmp,j)){printf("%lld\n",j);f=true;break;}
    }while(j<=sqrt(tmp)-1);
    if(!f) for(j=tmp/sqrt(tmp)-1;j>=1;j--) if(tmp%j==0){printf("%lld\n",tmp/j-1);break;}
  }
  return 0;
}
