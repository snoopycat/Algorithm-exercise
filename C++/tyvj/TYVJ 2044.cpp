#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
struct sth
{
       int zuo,you;
}lu[200010];
int n,m,k;
long long int ans;
int fa[100010];
int getfa(int x)
{
    if(fa[x]==0)  return x;
    else return getfa(fa[x]);
}
void hb(int x,int y)
{
     if(fa[x]!=0)
     hb(fa[x],y);
     fa[x]=y;
}
int main()
{
    int x,y;
    cin>>n>>m>>k;
    int i,j;
    int a;
    for(i=1;i<=m;i++)
    {
    scanf("%d%d",&lu[i].zuo,&lu[i].you);
    if(lu[i].zuo>lu[i].you)
    {
    a=lu[i].zuo;
    lu[i].zuo=lu[i].you;
    lu[i].you=a;
    } 
      if(lu[i].zuo<=k && lu[i].you<=k)
        {
            x=getfa(lu[i].zuo);
            y=getfa(lu[i].you);
            if(x!=y)
            {
              hb(lu[i].zuo,y);
            }
            else
            ans++;
        }
         if(lu[i].zuo>k && lu[i].you>k)      
         {
                        
            x=getfa(lu[i].zuo);
            y=getfa(lu[i].you);
            if(x!=y)
            hb(lu[i].zuo,y);
         }    
}
     for(i=1;i<=m;i++)
    {
       if(lu[i].zuo<=k && lu[i].you>k)
       {
            x=getfa(lu[i].zuo);
            y=getfa(lu[i].you);
            if(x!=y)
            {
              hb(lu[i].zuo,y);
            }
            else
            ans++;
       }
    }
    cout<<ans<<endl;
    
    system("pause");
    return 0;
}
