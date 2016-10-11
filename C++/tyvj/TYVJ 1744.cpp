#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;
int zhengtree[1500010],fangtree[1500010];
int num[100010];
int xg[100010],last[100010],pre[100010];
int gs[100010],yuan[100010];
long long  ans[100010];
int n,m;
int maxx;
__int64 answer;
void addtree1(int l,int r,int k,int x)
{
     if(l>x || r<x)  return;
     if(l==r)   {zhengtree[k]++;return;}
     int mid;
     mid=(l+r)>>1;
     addtree1(l,mid,k<<1,x);
     addtree1(mid+1,r,(k<<1)+1,x);
     zhengtree[k]=zhengtree[k<<1]+zhengtree[(k<<1)+1];
}
void addtree2(int l,int r,int k,int x)
{
     if(l>x || r<x)  return;
     if(l==r)   {fangtree[k]++;return;}
     int mid;
     mid=(l+r)>>1;
     addtree2(l,mid,k<<1,x);
     addtree2(mid+1,r,(k<<1)+1,x);
     fangtree[k]=fangtree[k<<1]+fangtree[(k<<1)+1];
}
int ask1(int l,int r,int zuo,int you,int k)
{
    if(l>r || zuo>you) return 0;
    if(l>you || r<zuo)  return 0;
    if(l>=zuo && r<=you)  return zhengtree[k];
   // if(l==r)  return zhengtree[k];
    int mid;
     mid=(l+r)>>1;
     return ask1(l,mid,zuo,you,k<<1)+ask1(mid+1,r,zuo,you,(k<<1)+1);
}
int ask2(int l,int r,int zuo,int you,int k)
{
    if(l>r || zuo>you)  return 0;
    if(l>you || r<zuo)  return 0;
    if(l>=zuo && r<=you)  return fangtree[k];
   // if(l==r)  return fangtree[k];
    int mid;
    mid=(l+r)>>1;
    return ask2(l,mid,zuo,you,k<<1)+ask2(mid+1,r,zuo,you,(k<<1)+1);
}
int main()
{
    scanf("%d%d",&m,&n);
    int i,j;
    for(i=1;i<=m;i++)
    {
    scanf("%d",&num[i]);
    if(num[i]>maxx) 
    maxx=num[i];
    }
    for(i=1;i<=n;i++)
    {
      scanf("%d%d",&xg[i],&gs[i]);
      pre[i]=last[xg[i]];
      last[xg[i]]=i;
    }
    
    for(i=1;i<=m;i++)
    {
    yuan[i]+=ask1(1,maxx,num[i]+1,maxx,1);
    answer+=yuan[i];
    j=last[i];
    while(j>0)
    {
       ans[j]+=ask1(1,maxx,gs[j]+1,maxx,1);
       j=pre[j];
    }
    addtree1(1,maxx,1,num[i]);
    }
    for(i=m;i>=1;i--)
    {
    j=last[i];
    yuan[i]+=ask2(1,maxx,1,num[i]-1,1);
    while(j>0)
    {
       ans[j]+=ask2(1,maxx,1,gs[j]-1,1);
       j=pre[j];
    }
    addtree2(1,maxx,1,num[i]);
    }
    cout<<answer<<endl;
    for(i=1;i<=n;i++)
    {
     printf("%I64d\n",answer-yuan[xg[i]]+ans[i]);
    }
    system("pause");
    return 0;
}
