//By EriR @ 2019-02-10 20:32:28
//18ms 0.67MB
//dfs+搜索

#include<cstdio>
#include<string>
#include<iostream>
using std::cin;
using std::string;
int n,len,vis[25];
string s[25];
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
int check(string s1,string s2){
  int len1=s1.length(),len2=s2.length();
  for(register int i=1;i<=min(len1,len2);i++){
    int f=1;
    for(register int j=0;j<i;j++) if(s1[len1-i+j]!=s2[j]){f=0;break;}
    if(f) return i;//有重叠部分返回重叠开始的下标
  }
  return 0;//没有重叠部分返回0
}
void solve(string snow,int lennow){
  len=max(len,lennow);//更新最大长度
  for(int i=1;i<=n;i++){
    if(vis[i]>=2) continue;//字符串最多被使用2次
    int t=check(snow,s[i]);//获取重叠部分的长度
    if(t){//有重叠部分就开始dfs
      vis[i]++;
      solve(s[i],lennow+s[i].length()-t);
      vis[i]--;
    }
  }
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n+1;i++) cin>>s[i];
  solve(s[n+1],1);
  printf("%d",len);
  return 0;
}
