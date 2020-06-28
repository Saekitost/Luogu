//By EriR @ 2019-01-15 21:34:23
//16ms 0.77MB
//数论

#include<cstdio>
#include<cmath>
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=sqrt(n*m);i++) if((n*m)%i==0&&gcd(i,(n*m)/i)==n) ans+=2;//轮换式只枚举一半，每次结果+2
    printf("%d",ans);
    return 0;
}
