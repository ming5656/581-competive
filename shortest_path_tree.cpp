#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define oo 9999999999
struct dis
{
    int d;
    ll w;
    bool operator <(const dis& b)const
    {
        return w > b.w;
    }
    dis(int a,ll b)
    {
        d = a;
        w = b;
    }
};

vector<dis>* graph;
int n,m,q;
ll solve(int s)
{
    ll weight[n];
    ll dist[n];
    fill_n(weight,n,oo);
    fill_n(dist,n,oo);
    priority_queue<dis> pq;
    pq.push(dis(s,0));
    weight[s] = 0;
    dist[s] = 0;
    while(!pq.empty())
    {
        int u = pq.top().d;
        //ll nw = pq.top().w;
        pq.pop();
        for( int i=0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].d;
            ll nw = graph[u][i].w;
            if(dist[v]>dist[u]+nw)
            {
                dist[v] = dist[u] + nw;
                weight[v] = nw;
                pq.push(dis(v,dist[v]));
            }
            else if(dist[v]==dist[u]+nw)
            {
                weight[v] = min(weight[v],nw);
            }
        }
    }
    ll ans(0);
    for(int i=0;i<n;i++)
    {
        if(dist[i]==oo)
            return -1;
        ans+=weight[i];
    }
    return ans;
}
int main()
{
    int t,u,v,r;
    ll w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&q);
        graph = new vector<dis>[n];
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%lld",&u,&v,&w);
            graph[u].push_back(dis(v,w));
        }
        for(int i=0;i<q;i++)
        {
            scanf("%d",&r);
            ll ans =solve(r);
            if(ans==-1)
                printf("No\n");
            else
                printf("%lld\n",ans);
        }
        delete[] graph;
    }
    return 0;
}
