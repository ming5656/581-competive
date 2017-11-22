#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
#include <functional>
#define ll long long
#define edge pair<int,long long>

using namespace std;

struct node
{
    int s,d;
    ll r,w;
    bool operator <(const node &b)const
    {
        if(r==b.r)
        {
            return w<b.w;
        }
        return r<b.r;
    }
};
struct graph
{
    ll minR;
    vector<edge> *head;
};
struct compare
{
    bool operator()(edge const& a, edge const& b) const
    {
        return a.second > b.second;
    }
};
bool bfs(graph *g,int n)
{
    bool *visit=new bool[n];
    fill_n(visit,n,false);
    queue<int> q;
    q.push(0);
    visit[0]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g->head[u].size();i++)
        {
            if(!visit[g->head[u][i].first])
            {
                visit[g->head[u][i].first]=true;
                q.push(g->head[u][i].first);
            }
        }
        if(visit[n-1])
        {
            delete []visit;
            return true;
        }
    }
    bool f=visit[n-1];
    delete []visit;
    return f;
}

graph *findRisk(int n,vector<node> e)
{
    if(n==1)
    {
        graph *g=new graph;
        g->head=new vector<edge> [n];
        g->minR=0;
        return g;
    }
    int low=-1,heigh=e.size()-1,mid;
    graph *g=new graph;
    g->head=new vector<edge> [n];
    for(int i=0;i<=heigh;i++)
    {
        g->head[e[i].s].push_back(make_pair(e[i].d,e[i].w));
    }
    if(bfs(g,n)==false)
    {
        delete []g->head;
        return NULL;
    }
    delete []g->head;
    g->head=NULL;
    while((heigh-low)>1)
    {
        mid=(heigh-low)/2+low;
        delete []g->head;
        g->head=new vector<edge> [n];
        for(int i=0;i<=mid;i++)
        {
            g->head[e[i].s].push_back(make_pair(e[i].d,e[i].w));
        }
        if(bfs(g,n))
            heigh=mid;
        else
            low=mid;
    }
    delete []g->head;
    g->head=new vector<edge> [n];
    for(int i=0;e[i].r<=e[heigh].r;i++)
    {
        g->head[e[i].s].push_back(make_pair(e[i].d,e[i].w));
    }
    g->minR=e[heigh].r;
    return g;
}


ll dijsktra(graph *g,int n)
{
    priority_queue<edge,vector<edge>,compare> mm;
    mm.push(make_pair(0,0));
    bool *visit=new bool[n];
    ll *dis=new ll[n];
    fill_n(dis,n,92233720368547758);
    dis[0]=0;
    fill_n(visit,n,false);
    while(!mm.empty())
    {
        int u=mm.top().first;
        ll l=mm.top().second;
        mm.pop();
        if(visit[u])
            continue;
        visit[u]=true;
        for(int i=0;i<g->head[u].size();i++)
        {
            int v=g->head[u][i].first;
            ll sl=g->head[u][i].second;
            if(!visit[v])
            {
                if(dis[v]>l+sl)
                {
                    dis[v]=l+sl;
                    mm.push(make_pair(v,dis[v]));
                }
            }
        }
    }
    ll ans;
    if(visit[n-1])
        ans=dis[n-1];
    else
        ans=-1;
    delete []visit;
    delete []dis;
    return ans;
}
int main()
{
    int t,n,m;
    graph *g;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        vector<node> adde(m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%lld%lld",&adde[i].s,&adde[i].d,&adde[i].r,&adde[i].w);
        }
        sort(adde.begin(),adde.end());
        g=findRisk(n,adde);
        if(g==NULL)
        {
            printf("-1\n");
            continue;
        }
        ll wei=dijsktra(g,n);
        if(wei==-1)
        {
            printf("-1\n");
            continue;
        }
        printf("%lld %lld\n",g->minR,wei);
        delete []g->head;
        delete g;
    }
    return 0;
}
