//By EriR @ 2019-01-19 09:08:07
//291ms 1.05MB
//数学推导+枚举

#include<cstdio>
int w[40005],A[40005],B[40005],C[40005],D[40005];
int x[40005];
int main(){
  int dis,su=0;
  int a,b,c,d,n,m,i;
  scanf("%d%d",&n,&m);
  for(i=1;i<=m;i++){
    scanf("%d",&x[i]);
    w[x[i]]++;
  }
  for(dis=1;(9*dis+2)<=n;dis++,su=0){
    for(a=n-(9*dis+1);a>=1;a--){
      b = a+2*dis,c = b+6*dis+1,d = c+dis;
      su+=w[c]*w[d];
      A[a]+=su*w[b];
      B[b]+=su*w[a];
    }
  }
  for(dis=1;(9*dis+2)<=n;dis++,su=0){
    for(d=9*dis+2;d<=n;d++){
      c = d-dis,b = c-6*dis-1,a = b-2*dis;
      su+=w[a]*w[b];
      C[c]+=su*w[d];
      D[d]+=su*w[c];
    }
  }
  for(i=1;i<=m;i++) printf("%d %d %d %d\n",A[x[i]],B[x[i]],C[x[i]],D[x[i]]);
  return 0;
}
