#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct sth
{
     int zuo,you;
}qj[2010];
int n;
int num[5010],shu[5010],nsz,sz;
int to[5010],p[5010],pre[5010],last[5010],bsz;
int f[5010][5010];
inline bool comp(int a,int b)
{
       return a<b;
}
int find(int x)
{
    for(int i=1;i<=sz;i++)  if(shu[i]==x)  return i;
}
void Ins(int a,int b,int c)
{
     bsz++;to[bsz]=b;p[bsz]=c;pre[bsz]=last[a];last[a]=bsz;
}
int DP(int l,int r)
{
    if(f[l][r]>=0)  return f[l][r];
    if(l<r)  f[l][r]=DP(l+1,r);else f[l][r]=0;
    int i=last[l],tot=0,x;
    while(i>0)
    {
        x=to[i];
        if(x==r)  tot++;
        if(x>=r)  {i=pre[i];continue;}
        DP(l,x);DP(x,r);
        f[l][r]=max(f[l][r],f[l][x]+f[x][r]);
        i=pre[i];
    }
    return f[l][r]+=tot;
}
void print(int l,int r)
{
     int i=last[l];
     while(i>0)
     {
         if(to[i]==r)  
         {printf("%d ",p[i]);f[l][r]--;}
         i=pre[i];
     }
     if(f[l][r]==f[l+1][r])  {print(l+1,r);return;}
     i=last[l];
     while(i>0)
     {
         if(to[i]<r && f[l][to[i]]+f[to[i]][r]==f[l][r])  
         {print(l,to[i]);print(to[i],r);return;}
         i=pre[i];
     }
}
int main()
{
    int i,a,b,w,r;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  
    {
        scanf("%d%d",&w,&r);
        qj[i].zuo=w-r;qj[i].you=w+r;
        nsz++;num[nsz]=w-r;nsz++;num[nsz]=w+r;
    }
    num[0]=-100000;
    sort(num+1,num+1+nsz,comp);
    for(i=1;i<=nsz;i++) if(num[i]!=num[i-1])  {sz++;shu[sz]=num[i];}
    for(i=1;i<=n;i++)
    {
        a=find(qj[i].zuo);b=find(qj[i].you);
        Ins(a,b,i);
    }
    memset(f,-1,sizeof(f));
    printf("%d\n",DP(1,sz));
    print(1,sz);
    system("pause");
    return 0;
}
/*
4
1 1
2 2
4 1
5 1
*/
