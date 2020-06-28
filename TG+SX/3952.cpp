//By EriR @ 2019-01-31 14:58:08
//36ms 0.78MB
//栈模拟

#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
const int MAXL = 105;
int n,m,t1,t2;
string O,code[MAXL];
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return f*x;
}
int get_num(int &x,string tmp){
  int res=0;
  while(tmp[x]<'0'||tmp[x]>'9'&&x<tmp.size()){
    if(tmp[x]=='n'){x++;return 0x3f3f3f3f;}
    x++;
  }
  while(tmp[x]>='0'&&tmp[x]<='9'){res=res*10+tmp[x]-'0';x++;}
  return res;
}
int max(int x,int y){return x>y?x:y;}
int get_O(){
  int res=0,p=3;
  if(O[2]=='n') res=get_num(p,O);
  else res=0;
  return res;
}
int check(){
  stack<int> s;
  int a,b,x,res=0,st=0,flag=-1;
  bool alp[26]={0},ano[26]={0};
  for(int i=1;i<=m;i++){
    if(code[i][0]=='F'){
      int k=code[i][2]-'a';
      if(alp[k]) return -1;
      s.push(k);alp[k]=true;x=4;
      a=get_num(x,code[i]);b=get_num(x,code[i]);
      if(b-a>1000) if(flag==-1){st++;res=max(res,st);ano[k]=true;}
      if(a>b) if(flag==-1) flag=k;
    }
    if(code[i][0]=='E'){
      if(s.empty()) return -1;
      int k=s.top();s.pop();
      alp[k]=false;
      if(flag==k) flag=-1;
      if(ano[k]){ano[k]=false;st--;}
    }
  }
  if(s.size()) return -1;
  return res;
}
int main(){
  n=read();
  while(n--){
    scanf("%d ",&m);getline(cin,O);//m为代码行数
    for(int i=1;i<=m;i++) getline(cin,code[i]);
    t1=get_O(),t2=check();
    if(t2==-1) puts("ERR");
    else t1==t2?puts("Yes"):puts("No");
  }
  return 0;
}
