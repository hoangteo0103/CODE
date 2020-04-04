#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int >  ii;
const int N =1e5+9;
vector<ii> g[N];
ii dist[N];
int f[N],f1[N],f2[N],par[N],l;
int res=0;
bool ok[N];
int n,q;
void checkmax(int &x,int y)
{
    if(y>x) x=y;
}
int root(int x)
{
    return par[x]<0 ? x : par[x]=root(par[x]);
}
void merge(int x,int y)
{
    x=root(x);
    y=root(y);
    if(x==y) return;
    if(par[x]>par[y]) swap(x,y);
    par[x]+=par[y];
    res=max(res,abs(par[x]));
    par[y]=x;
}
void add(int x)
{   ok[x]=true;
    for(auto tt:g[x])
    {
        int v=tt.first;
        if(ok[v])
        {
         merge(x,v);
        }
    }
}
void del(int x)
{
    ok[x]=false;
    par[root(x)]++;
}
void In()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    memset(f,0,sizeof(f));
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
}
void down(int u, int par)
{
    for(auto tt:g[u])
    {
        int v=tt.first;
        int w=tt.second;
        if(v==par) continue;
        down(v,u);
        if(f[u]<f[v]+w)
        {
            f1[u]=f[u];
            f[u]=f[v]+w;
        }
        else checkmax(f1[u],f[v]+w);
    }
}
void up(int u,int par)
{
    for(auto tt:g[u])
    {
        int v=tt.first;
        int w=tt.second;
        if(v==par) continue;
        f2[v]=max(f2[u],((f[v]+w) ==f[u]) ? f1[u] :f[u   ])+w;
        up(v,u);
    }
}
void backup()
{
    down(1,1);
    up(1,1);
    for(int i=1;i<=n;i++)
        dist[i]={max(f[i],f2[i]),i};//cout<<dist[i].first<<' ';
    sort(dist+1,dist+n+1,greater<ii>());
}
void Solve()
{
    res=1;
    cin>>l;
    for(int i=1;i<=n;i++)
        par[i]=-1,ok[i]=false;
    int j=1;
    for(int i=1;i<=n;i++)
    {
        if(i>1) del(dist[i-1].second);
        while(j<=n && dist[i].first-dist[j].first<=l) add(dist[j++].second);
    }
    cout<<res<<endl;
}
#undef int
int main()
{   freopen("trash.inp","r",stdin);
    In();
    backup();
    cin>>q;
    while(q--)
    Solve();
}

