#include<iostream>
#include<stdio.h>
using namespace std;
bool mark[200002][53];
int a[200002][53];
int b[200002];
int n,k,l;
int ans;
int last;
int main()
{   
	int aa;
	int i,j;
	cin>>n>>k>>l;
	cin>>aa>>b[1];
	a[1][aa]++;mark[1][aa]=1;
	for(i=2;i<=n;i++)
	{
	for(j=0;j<=k-1;j++)
	a[i][j]=a[i-1][j];
	scanf("%d%d",&aa,&b[i]);
	a[i][aa]++;mark[i][aa]=1;
	
	}
	for(i=1;i<=n;i++)
	{
	if(b[i]<=l)
	{
	for(j=0;j<=k-1;j++)
	{
	    if(!mark[i][j])
		ans+=(a[i][j]-a[last][j])*(a[n][j]-a[i][j]);
	    else
		ans+=(a[i][j]-a[last][j]-1)*(a[n][j]-a[i][j]+1)+a[n][j]-a[i][j];
    }
	last=i;
	}
    }
   cout<<ans<<endl;
	return 0;
}