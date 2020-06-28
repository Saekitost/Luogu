//By EriR @ 2019-01-24 21:02:30
//31ms 0.78MB
//字符串+数学模拟

#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int n,t;
  cin>>n;
  for(int i=n;i>=0;i--){
    cin>>t;
    if(t){//主要是对数和条件的筛选比较容易出错
        if(i!=n&&t>0) cout<<"+";
        if(abs(t)>1||i==0) cout<<t;
        if(t==-1&&i) cout<<"-";
        if(i>1) cout<<"x^"<<i;
        if(i==1) cout<<"x";
    }
  }
  return 0;
}
