#include <bits/stdc++.h>

#define ll long long
ll pos[50005],n,k;
using namespace std;

bool check(ll len)
{
    ll cnt(0);
    for(ll i=0;i<n;i++)
    {
        cnt++;
        if(cnt>k)
            return false;
        if((pos[n-1]<=pos[i]+len)&&(cnt<=k))
            return true;
        ll bou = pos[i]+len;
        while((i+1)<n&&(pos[i+1]<=bou))
              i++;
    }
    return false;
}
int main()
{
    int t;
    ll l,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&pos[i]);
        }
        sort(pos,pos+n);
        if(k==1)
        {
            printf("%lld\n",pos[n-1]-pos[0]);
            continue;
        }
        l=1;
        r = (pos[n-1]-pos[0])/k+1;
        while(l<r)
        {
            ll mid = (l +r)/2;
            if(check(mid))
            {
                r=mid;
            }
            else
            {
                l = mid+1;
            }
            if(l==r)
                break;
        }
        printf("%lld\n",r);
    }
    return 0;
}
