//By EriR @ 2019-01-31 10:31:39
//13ms 0.77MB
//dfs+搜索

#include<cstdio>
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return f*x;
}
struct path{
  int x,y;
}paths[105];
int n,vis[105][105];
int dir[]={0,-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
char s[105][105],word[]="yizhong";
void dfs(int x,int y,path paths[],int k,int cnt){
  if(cnt==7) for(int i=0;i<7;i++) vis[paths[i].x][paths[i].y]=1;
  else{
    int dx=x+dir[k*2-1],dy=y+dir[k*2];
    if(cnt==6||s[dx][dy]==word[cnt+1]){
      paths[cnt].x=x,paths[cnt].y=y;
      dfs(dx,dy,paths,k,cnt+1);
    }
  }
}
int main(){
  n=read();
  for(int i=0;i<n;i++) scanf("%s",&s[i]);
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(s[i][j]=='y'){
    for(int k=1;k<=8;k++){
      int dx=i+dir[k*2-1],dy=j+dir[k*2];
      if(s[dx][dy]=='i') dfs(i,j,paths,k,0);
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) if(vis[i][j]) printf("%c",s[i][j]); else printf("*");
    puts("");
  }
  return 0;
}
