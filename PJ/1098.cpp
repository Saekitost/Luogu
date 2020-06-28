//By EriR @ 2019-02-19 16:26:13
//30ms 0.78MB
//模拟+字符串处理

#include<cstdio>
#include<iostream>
using std::cout;
using std::endl;
int i,j,k,p1,p2,p3;
char pre,bac,mid,t,s[105];
int main(){
  scanf("%d%d%d%s",&p1,&p2,&p3,s);
  while(s[i]){
    pre=s[i-1],mid=s[i],bac=s[i+1];//重点：for循环内的三目运算符/char与int的直观 + -(划重点)
    if(mid=='-'&&bac>pre&&((pre>='0'&&bac<='9')||(pre>='a'&&bac<='z'))){
      for(j=(p3==1)?pre+1:bac-1;p3==1?j<bac:j>pre;p3==1?j++:j--){
        t=j;//将ASCII码为j的字符赋给t
        if(p1==1) t=(t>='A')?(t<='Z')?t+32:t:t;//p1=1且为字母时就变成小写
        else if(p1==2) t=(t>='A')?(t>='a')?t-32:t:t;//大写
        else if(p1==3) t='*';//否则判断是否输出'*'
        for(k=1;k<=p2;k++) printf("%c",t);//输出p2个
      }
    }
    else printf("%c",mid);
    i++;
  }
  return 0;
}
