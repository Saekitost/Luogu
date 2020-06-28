//By EriR @ 2019-01-19 09:10:22
//216ms 1.04MB
//高精+数论

#include<cstdio>
#include<cmath>
#include<cstring>
struct bignum{
  int w[1200];
  friend bignum operator *(bignum a,bignum b){
    bignum ans;
    int i,j;
    for(i=0;i<500;i++) for(j=0;j<500;j++) ans.w[i+j] += a.w[i]*b.w[j];
    for(i=0;i<500;i++) ans.w[i+1]+=ans.w[i]/10,ans.w[i]%=10;
    for(;i<1010;i++) ans.w[i] = 0;
    return ans;
  }
  void minus(){w[0]--;}
  void out(){
    int i,cnt=0;
    for(i=499;i>=0;i--) (++cnt)%50==0?printf("%d\n",w[i]):printf("%d",w[i]);
  }
  bignum(int x=0){
    memset(w,0,sizeof(w));
    w[0] = x;
  }
};
bignum one(1),two(2);
bignum Pow(bignum x,int p){
  if(p==0) return one;
  if(p==1) return x;
  bignum a = Pow(x,p/2);
  if(p%2==0) return a*a;
  return a*a*x;
}
int main(){
  int t;
  scanf("%d",&t);
  printf("%d\n",int(double(t)*log10(2)+1));//求位数:log10(n)+1即可求出n的位数
  bignum ans = Pow(two,t);
  ans.minus();
  ans.out();
  return 0;
}
