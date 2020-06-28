//By EriR @ 2019-01-15 21:08:55
//10ms 0.79MBs
//字符串排序

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a,string b){return a+b>b+a;}//巧妙的字典序排序
int main(){
  int n,i;
  string s[25];
  scanf("%d",&n);
  for(i=0;i<n;i++) cin>>s[i];
  sort(s,s+n,cmp);
  for(i=0;i<n;i++) cout<<s[i];
  cout<<endl;
  return 0;
}
