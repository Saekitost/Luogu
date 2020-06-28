//By EriR @ 2019-01-21 20:18:17
//56ms 0.78MB
//数学递推

#include<cstdio>
int main(){
    int n,i,f[1010];
    f[0]=f[1]=1;
    scanf("%d",&n);
    for(i=2;i<=n;i++) if(i%2==0) f[i]=f[i-1]+f[i/2]; else f[i]=f[i-1];
    printf("%d\n",f[n]);
}
