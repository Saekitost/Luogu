//By EriR @ 2019-01-22 20:17:58
//35ms 0.78MB
//贪心+排序

#include<cstdio>
#include<algorithm>
using namespace std;
int tmp=0,cnt=0;
struct inf{//保存这个人最初的序号和所需要的时间
  int n,v;
}a[1005];
bool cmp(inf x,inf y){//cmp按照时间排序
  if(x.v!=y.v) return x.v<y.v;
  return x.n<y.n;
}
int main(){
  int n,i;
  double sum=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&a[i].v);
    a[i].n = i;
  }
  sort(a+1,a+n+1,cmp);//排序后从小到大开始贪心
  for(i=1;i<=n;i++) i!=n?printf("%d ",a[i].n):printf("%d\n",a[i].n);
  for(i=1;i<=n;i++) sum+=i*a[n-i].v;//坑点：对于每个人，在场剩余的人都要经历一次他的打水时间，要乘以 i
  printf("%.2lf",sum/n);
  return 0;
}
