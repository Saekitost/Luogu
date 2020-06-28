//By EriR @ 2019-01-24 21:34:51
//32ms 0.77MB
//STL代替模拟

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> mem;//vector表示内存
int main(){
  int m,n,t,cnt=0;
  cin>>m>>n;
  for(int i=n;i>0;i--){
    cin>>t;//先find是否在内存中，否则就加入到内存并cnt++
    if(find(mem.begin(),mem.end(),t)==mem.end()){mem.push_back(t);cnt++;}
    if(mem.size()>m) mem.erase(mem.begin());//内存爆了就就把最前面的单词erase
  }
  cout<<cnt;
  return 0;
}
