#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll p;

using namespace std;


ll invert(ll num)
{
    ll q = p-2,ans(1),base = num;
    while(q>0)
    {
        if(q&1)
        {
            ans= (ans *base)% p;
        }
        q>>=1;
        base = (base *base)% p;
    }
    return ans;
}
struct number
{
    ll value,times;
};
int main()
{
    int t,n;
    ll temp;
    vector<ll> up,down;
    vector<number> up2,down2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&p);
        for(int i=0;i<n/2;i++)
        {
            scanf("%lld",&temp);
            temp = invert(temp);
            int len= up.size();
            for(int j=0;j<len;j++)
            {
                ll product =(temp*up[j])%p;
                if(product==0)
                    continue;
                up.push_back(product);
            }
            up.push_back(temp);
        }
        sort(up.begin(),up.end());
        for(int i=0;i<up.size();)
        {
            number d;
            d.value=up[i];
            d.times=0;
            while(i<up.size()&&up[i]==d.value)
            {
                d.times++;
                i++;
            }
            up2.push_back(d);
        }

/*------------------------------*/
        for(int i=n/2;i<n;i++)
        {
            scanf("%lld",&temp);
            int len= down.size();
            for(int j=0;j<len;j++)
            {
                ll product =(temp*down[j])%p;
                if(product==0)
                    continue;
                down.push_back(product);
            }
            down.push_back(temp);
        }
        sort(down.begin(),down.end());
        for(int i=0;i<down.size();)
        {
            number d;
            d.value=down[i];
            d.times=0;
            while(i<down.size()&&down[i]==d.value)
            {
                d.times++;
                i++;
            }
            down2.push_back(d);
        }
        ll ans(0);
        for(int i=0,j=0;i<up2.size()&&j<down2.size();)
        {
            if(up2[i].value==down2[j].value)
            {
                ans += (up2[i].times * down2[j].times);
                i++;
                j++;
            }
            else if(up2[i].value > down2[j].value)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        if(up2.size()>0&&up2[0].value==1)
        {
            ans+=up2[0].times;
        }
        if(down2.size()>0&&down2[0].value==1)
        {
            ans+=down2[0].times;
        }
        printf("%lld\n",ans);
        up.clear();
        down.clear();
        up2.clear();
        down2.clear();
    }
    return 0;
}
