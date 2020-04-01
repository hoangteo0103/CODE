#include<bits/stdc++.h>
using namespace std;
const long long  N =2e5+200;
const long long  mod=1e9+7;
long long  n,dp1[N],dp2[N];
vector<long long > g[N];
long long  nhan(int a,int   b)
{
    return (1LL*a*b)%mod;
}
void In()
{
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        g[x].push_back(i);
    }
    for(int i=1;i<N;i++)
        dp1[i]=dp2[i]=1;
}
void down(int u)
{
    for(int v:g[u])
    {
        down(v);
        dp1[u]=nhan(dp1[u],dp1[v]+1);
    }
}
void up(int u)
{
    if(g[u].empty()) return;
    int nn=g[u].size();
    vector<int> pre(nn),suf(nn);
    pre[0]=suf[nn-1]=1;
    for(int i=1;i<nn;i++)
    pre[i]=nhan(pre[i-1],dp1[g[u][i-1]]+1);
    for(int i=nn-2;i>=0;i--)
    suf[i]=nhan(suf[i+1],dp1[g[u][i+1]]+1);
    for(int i=0;i<nn;i++)
    {
        int v=g[u][i];
        dp2[v]=nhan(nhan(suf[i],pre[i]),dp2[u])+1;
        up(v);
    }
}
void Solve()
{
    down(1);
    up(1);
    for(int i=1;i<=n;i++)
        cout<<nhan(dp1[i],dp2[i])<<' ';
}
int main()
{
    freopen("trash.inp","r",stdin);
    In();
    Solve();
}
