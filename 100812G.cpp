#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int > ii ;
const int N =1e5+10;
int n,m,par[N],badboy[N];
long long d[N];
vector<ii> g[N];
struct edge{
    int u,v,w;
};
vector<edge> edges;
priority_queue<ii ,vector<ii > , greater<ii > > heap;
void In()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>badboy[i];
    for(int i=1;i<=m;i++)
    {
        int u ,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        edges.push_back({u,v,w});
    }
    for(int i=1;i<=n;i++)
    if(badboy[i])
    {
        par[i]=i;
        d[i]=0;
        heap.push({0,i});
    }
    else d[i]=1e15;
}
void Solve()
{
    while(!heap.empty())
    {
        int u=heap.top().second;
        long long  du=heap.top().first;
        heap.pop();
        if(d[u]<du) continue;
        for(auto tt:g[u])
        {
            int w=tt.second;
            int v=tt.first;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                par[v]=par[u];
                heap.push({d[v],v});
            }
        }
    }
}
void Out()
{
     long long res=1e15,ans1,ans2;
    for(edge tt:edges )
    {
        int u=tt.u,v=tt.v,w=tt.w;
        if(par[u]!=par[v] && d[u]+d[v]+w <res)
        {
            ans1=par[u];
            ans2=par[v];
            res=d[u]+d[v]+w;
        }
    }
    if(res<1e15)
        cout<<res<<'\n'<<ans1<<' '<<ans2;
    else cout<<"No luck at all";
}
int main()
{   //freopen("trash.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    In();
    Solve();
    Out();
}
