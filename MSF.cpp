#include <bits/stdc++.h>

using namespace std;

#define oo 999999999
#define ll long long

struct edge
{
    int u,v;
    ll w;
    bool operator <(const edge& b)const
    {
        return w<b.w;
    }
};
int parent[10005],Rank[10005];
edge graph[500005];
int n,m,k;
int f(int u)
{
    while(u!=parent[u])
    {
        u = parent[u];
    }
    return u;
}
void unin(int u,int v)
{
    if(u!=v)
    {
        if(Rank[u]>Rank[v])
        {
            parent[v] = u;
        }
        else if(Rank[u]<Rank[v])
        {
            parent[u] = v;
        }
        else
        {
            parent[u] = v;
            Rank[v]++;
        }
    }
}
ll kruskal()
{
    sort(graph,graph+m);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        Rank[i] = 1;
    }
    int ne = n-k;
    ll ans(0);
    bool exist(false);
    for(int i=0;i<m;i++)
    {
        int p = f(graph[i].u);
        int q = f(graph[i].v);
        if(p!=q)
        {
            unin(p,q);
            ne--;
            ans+=graph[i].w;
        }
        if(!ne)
        {
            exist =true;
            break;
        }
    }
    if(exist)
        return ans;
    else
        return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<m;i++)
            scanf("%d%d%lld",&graph[i].u,&graph[i].v,&graph[i].w);
        ll ans =kruskal();
        cout<<ans<<endl;
    }
    return 0;
}



