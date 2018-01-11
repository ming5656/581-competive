#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define oo 999999999999999999
int n,m,parent[10005];
ll flow[10005][10005];
struct edge
{
    int d;
    ll c;
    edge(int a,ll b)
    {
        d =a;
        c = b;
    }
};
vector<edge> graph[10005];

ll bfs(int s,int t)
{
    bool visit[n];
    ll neck[n];
    memset(visit,0,sizeof(visit));
    //fill_n(neck,INT_MAX,n);
    neck[s] = oo;
    parent[s] = s;
    queue<int> q;
    visit[s] =true;
    q.push(s);
    while(!q.empty())
    {
        int u= q.front();
        q.pop();
        for(int v=0;v<n;v++)
        {
            //int v = graph[u][j];
            if(!visit[v]&&flow[u][v]>0)
            {
                neck[v] = min(neck[u],flow[u][v]);
                visit[v] = true;
                q.push(v);
                parent[v] = u;
                if(v==t)
                    return neck[v];
            }
        }
    }
    return 0;
}
ll edm()
{
    ll rf,ans(0);
    while((rf=bfs(0,n-1))>0)
    {
        ans+=rf;
        for(int i=n-1,j=parent[i];i!=j;i=j,j=parent[j])
        {
            flow[j][i]-=rf;
            flow[i][j]+=rf;
        }
    }
    return ans;
}
int main()
{
    //freopen("in.txt", "rt", stdin);
//freopen("out.txt", "w+t", stdout);
    int t,u,v;
    ll c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(flow,0,sizeof(flow));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%lld",&u,&v,&c);
            //graph[u].push_back(edge(v,c));
            flow[u][v] = c;
        }
        cout<<edm()<<endl;
    }
    return 0;
}
