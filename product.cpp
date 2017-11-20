#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll p;
ll num[45];

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
    bool operator <(const number &b) const
    {
        return value<b.value;
    }
};
ll dp(int n)
{
    vector<number> product ,buffer;
    number start ={1,1};
    product.push_back(start);
    for(int i=0;i<n;i++)
    {
        buffer.clear();
        vector<number> :: iterator it;
        for(int j=0;j<product.size();j++)
        {
            number d;
            d.value = (num[i] * product[j].value)%p;
            d.times = product[j].times;
            if(d.value==0)
                continue;
            else
            {
                buffer.push_back(d);
            }
        }
        for(int j=0;j<buffer.size();j++)
        {
            it = lower_bound(product.begin(),product.end(),buffer[j]);
            if(it==product.end())
            {
                product.push_back(buffer[j]);
            }
            else if(it->value==buffer[j].value)
            {
                it->times+=buffer[j].times;
            }
            else
            {
                product.insert(it,buffer[j]);
            }
        }
    }
    return product[0].times-1;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&p);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&num[i]);
            num[i]=invert(num[i]);
        }
        printf("%lld\n",dp(n));
    }
    return 0;
}
