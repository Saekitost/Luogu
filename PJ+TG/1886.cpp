//By EriR @ 2019-01-20 17:40:52
//1718ms 4.43MB
//单调队列+模拟

#include<cstdio>
#include<deque>
using namespace std;
int a[1000005],n,k;
int cr;
deque <int> qmax;
deque <int> qmin;
int check_max(int l,int r){
  while(cr!=r){
    cr++;
    while(!qmax.empty()&&a[qmax.back()]<=a[cr]) qmax.pop_back();
    qmax.push_back(cr);
  }
  while(!qmax.empty()&&qmax.front()<l) qmax.pop_front();
  return a[qmax.front()];
}
int check_min(int l,int r){
  while(cr!=r){
    cr++;
    while(!qmin.empty()&&a[qmin.back()]>=a[cr]) qmin.pop_back();
    qmin.push_back(cr);
  }
  while(!qmin.empty()&&qmin.front()<l) qmin.pop_front();
  return a[qmin.front()];
}
int main(){
  int i;
  scanf("%d%d",&n,&k);
  k--;
  for(i=1;i<=n;i++) scanf("%d",&a[i]);
  cr=0;
  for(i=1;i+k<=n;i++) i+k!=n?printf("%d ",check_min(i,i+k)):printf("%d\n",check_min(i,i+k));
  cr=0;
  for(i=1;i+k<=n;i++) i+k!=n?printf("%d ",check_max(i,i+k)):printf("%d\n",check_max(i,i+k));
  return 0;
}
