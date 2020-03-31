#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =3e6+9;
int n,m,a[N],num[N],p[N];
long long suf[N],ans[N];
void In()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
        num[a[i]]++;
    cin>>m;
    for(int i=1; i<=m; i++)
        cin>>p[i];
}
void Prepare()
{
    for(int i=1; i<=N; i++)
        for(int j=i; j<=N; j+=i)
        {
            if((j/i )!= i)
                ans[j]+=num[j/i]*num[i];
            else
                ans[j]+=num[i]*(num[i]-1);
        }

    suf[0]=0;
    for(int i=1; i<=N; i++)
        suf[i]=suf[i-1]+ans[i];
}
void Solve()
{
    for(int i=1; i<=m; i++)
        cout<<n*(n-1)-suf[p[i]-1]<<'\n';
}
#undef int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    In();
    Prepare();
    Solve();
}
