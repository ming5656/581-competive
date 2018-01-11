#include <bits/stdc++.h>

using namespace std;

#define oo 999999999
struct edge
{
    int u,v,w;
    edge(int a,int b,int c)
    {
        u = a;
        v = b;
        w = c;
    }
    bool operator <(const edge& b)const
    {
        return w > b.w;
    }
};
struct e
{
    int d,w;
    e(int a,int b)
    {
        d = a;
        w = b;
    }
};
vector<e>* graph;
long int mst(int n)
{
    vector<long int> key(n,oo);
    vector<bool> inMST(n,false);
    key[0] = 0;
    priority_queue<edge> pq;
    pq.push(edge(0,0,0));
    long int ans(0);
    while(!pq.empty())
    {
        edge x = pq.top();
        pq.pop();
        int nv;
        if(!inMST[x.u])
        {
            nv = x.u;
        }
        else if(!inMST[x.v])
        {
            nv = x.v;
        }
        else
            continue;
        int wet = x.w;
        ans+=wet;
        inMST[nv] = true;
        for(int i=0;i<graph[nv].size();i++)
        {
            int j = graph[nv][i].d;
            int nw = graph[nv][i].w;
            if(nw < key[j] && !inMST[j])
            {
                key[j] = nw;
                pq.push(edge(nv,j,nw));
            }
        }
    }
    return ans;
}
int main()
{
    int t,n,m,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        graph = new vector<e>[n];
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            graph[a].push_back(e(b,c));
            graph[b].push_back(e(a,c));
        }
        cout<<mst(n)<<endl;
        for(int i=0;i<n;i++)
            graph[i].clear();
        delete[] graph;
    }

    return 0;
}
