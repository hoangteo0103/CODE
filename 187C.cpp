#include<bits/stdc++.h>
using namespace std;
const int N =1e5+9;
int n,m,S,T,k,dist[N];
const int inf =1e9;
vector<int> g[N];
bool bus[N];
void In()
{
    cin>>n>>m>>k;
    memset(bus,0,sizeof(bus));
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        bus[x]=true;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin>>S>>T;
}
bool Check(int limit)
{
    queue<int> qu;
    for(int i=1;i<=n;i++)
        dist[i]=-1;
    dist[S]=0;
    qu.push(S);
    while(!qu.empty())
    {
        int u=qu.front();
        qu.pop();
        if(u==T) return true;
        if(dist[u]==limit) continue;
        for(int v:g[u])
        {
            int tmp=dist[u]+1;
            if(bus[v]) tmp=0;
            if(tmp<dist[v] || dist[v]==-1)
            {
                dist[v]=tmp;
                qu.push(v);
            }
        }
    }
    return dist[T]!=-1;
}
void solve()
{
    int low=1;
    int high=n-1;
    int ans=inf;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(Check(mid)) ans=mid,high=mid-1;
        else low=mid+1;
    }
    if(ans<inf)
    cout<<ans;
    else cout<<-1;
}
int main()
{   //freopen("trash.inp","r",stdin);
    In();
    solve();
}
