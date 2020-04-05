
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9;
const int len=5e8;
int n;
void ans(int x)
{
    cout<<"YES "<<x<<endl;
    exit(0);
}
int query(int mid)
{
    cout<<"QUERY "<<mid<<' '<<(mid+len-1)%MOD<<endl;
    int rac; cin>>rac;
    if (rac==n/2) ans(mid);
    return rac;
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    int rac=query(0);
    int low=0, high=5e8;
    for(int i=1; i<=28; ++i)
    {
        int mid=low+high>>1;
        int tmp=query(mid);
        if (tmp>n/2 && rac<n/2 || tmp<n/2 && rac>n/2) high=mid; else low=mid;
    }
    ans(lo+hi>>1);
}
