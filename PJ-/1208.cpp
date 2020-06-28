//By EriR @ 2019-01-22 20:16:13
//27ms 0.79MB
//贪心+排序

#include<cstdio>
#include<algorithm>
using namespace std;
struct inf{int num,pri;}a[5005];
bool cmp(inf x,inf y){return x.pri<y.pri;}
int main(){
  int sum,n,i=0;
  scanf("%d%d",&sum,&n);
  while(i<n){
    scanf("%d%d",&a[i].pri,&a[i].num);
    i++;
  }
  sort(a,a+n,cmp);
  i=0,n=0;
  while(sum>0){//不断贪心模拟
    if(a[i].num<=sum){
      sum-=a[i].num;
      n+=a[i].pri*a[i].num;
    }
    else if(a[i].num>sum){
      n+=a[i].pri*sum;
      break;
    }
    else break;
    i++;
  }
  printf("%d",n);
  return 0;
}
