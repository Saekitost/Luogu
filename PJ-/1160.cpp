//By EriR @ 2019-01-25 21:33:06
//55ms 1.43MB
//链表+模拟

#include<cstdio>
#include<cstring>
inline int read(){
  int f=1,x=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
  return f*x;
}
struct node{
  int pre,bac;
}a[100005];
int n,m;
int main(){
  int k,p,start=1;
  n=read();
  memset(a,0,sizeof(struct node)*n);
  a[1].pre=0;a[1].bac=0;
  for(register int i=2;i<=n;i++){
    k=read(),p=read();
    if(p){
      if(a[k].bac==0){a[k].bac=i;a[i].pre=k;a[i].bac=0;}
      else{a[a[k].bac].pre=i;a[i].bac=a[k].bac;a[k].bac=i;a[i].pre=k;}
    }
    else{
      if(a[k].pre==0){a[k].pre=i;a[i].bac=k;a[i].pre=0;start=i;}
      else{a[a[k].pre].bac=i;a[i].pre=a[k].pre;a[k].pre=i;a[i].bac=k;}
    }
  }
  m=read();p=n;
  for(register int i=1;i<=m;i++){
    k=read();
    if(a[k].pre==0&&a[k].bac==0) continue;
    if(a[k].pre==0){start=a[k].bac;a[a[k].bac].pre=0;a[k].pre=0;a[k].bac=0;p--;}
    else{
      if(a[k].bac!=0){a[a[k].pre].bac=a[k].bac;a[a[k].bac].pre=a[k].pre;a[k].pre=0,a[k].bac=0;p--;}
      else{a[a[k].pre].bac=0;a[k].pre=0,a[k].bac=0;p--;}
    }
  }
  for(int i=1;i<=p;i++){
    i!=p?printf("%d ",start):printf("%d\n",start);
    start=a[start].bac;
  }
  return 0;
}
