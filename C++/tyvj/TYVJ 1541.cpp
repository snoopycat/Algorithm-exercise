#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int p[10][362881]={0},w[362881]={0},goal[10]={0,1,2,3,8,0,4,7,6,5},h[362881]={0};
int f=1,b=1,power[10]={0,1};
int hash(int now)
{
int flag[10]={0},i,j,num,sum=1;
for(i=1;i<=9;i++)
{
num=0;
for(j=0;j<p[i][now];j++)
if(flag[j]==0)
num++;
flag[p[i][now]]=1;
sum+=num*power[9-i];
}
return sum;
}
void solve(int now,int now1)
{
int i,t,op;
b++;
for(i=0;i<=9;i++)
p[i][b]=p[i][f];  
w[b]=w[f]; 
t=p[now][b];
p[now][b]=p[now1][b];
p[now1][b]=t;
op=hash(b);
if(h[op]==0)
h[op]=1;
else b--;
}
int main()
{
int i,n,now;
for(i=1;i<=9;i++)
{
scanf("%c",&p[i][1]);
p[i][1]-='0';
}
for(i=2;i<=9;i++)
power[i]=power[i-1]*i;
while(f<=b)
{
for(i=1;i<=9;i++)
if(p[i][f]!=goal[i])
break;
if(i==10)
{
printf("%d",w[f]);

return 0;
}
w[f]++;
for(i=1;i<=9;i++)
if(p[i][f]==0)
break;
now=i;
if(now>3)
solve(now,now-3);
if(now<7)
solve(now,now+3);
if(now%3!=1)
solve(now,now-1);
if(now%3!=0)
solve(now,now+1);
f++;
}
}  
