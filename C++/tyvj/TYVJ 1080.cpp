#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int n,ans;
int num[20];
bool lie[20],zxie[30],fxie[30];
void dfs(int x,int top)
{
     if(top==n)
     {
       ans++;
       if(ans<=3)
       {
       int j;
       for(j=1;j<=n;j++)
       printf("%d ",num[j]);
       printf("\n");
       }
       return;
     }
     int i;
     for(i=1;i<=n;i++)
     {
     if(!lie[i] && !zxie[x-i+n] && !fxie[x+i])
     {
       lie[i]=1;zxie[x-i+n]=1;fxie[x+i]=1;
       num[x]=i;
       dfs(x+1,top+1);
       lie[i]=0;zxie[x-i+n]=0;fxie[x+i]=0;
     }
     }
}
int main()
{
    cin>>n;
    dfs(1,0);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
