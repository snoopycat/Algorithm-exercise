#include<iostream>
using namespace std;
int n;
int x[10001],y[10001],c[10001],g[10001];
int x1,y1;
bool o;
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>x[i]>>y[i]>>c[i]>>g[i];
    cin>>x1>>y1;
    for(i=n;i>=1;i--)
    {
      if((x1>=x[i])&&(x[i]+c[i]-1>=x1))
      if((y1>=y[i])&&(y[i]+g[i]-1>=y1))
      {cout<<i<<endl;o=1;break;}
    }
    if(!o)cout<<-1<<endl;
  //  system("pause");
    return 0;
}