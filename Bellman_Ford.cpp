#include <bits/stdc++.h>

using namespace std;

#define oo 99999999

struct edge
{
    int s,e,w;
    /*edge(int a,int b,int c)
    {
        s = a;
        e = b;
        w = c;
    }*/
};

int n,m,q;
edge* graph;
bool **reach;
bool *visit;
int **dis;
void bellman_ford(int src)
{
    visit[src] = true;
    fill_n(dis[src],n,oo);
    fill_n(reach[src],n,true);
    dis[src][src] = 0;
    bool change(false);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int ns = graph[j].s;
            int ne = graph[j].e;
            int nw = graph[j].w;
            if( dis[src][ns]!=oo && dis[src][ns]+nw < dis[src][ne])
            {
                dis[src][ne] = dis[src][ns] + nw;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        change = false;
        for(int j=0;j<m;j++)
        {
            int ns = graph[j].s;
            int ne = graph[j].e;
            int nw = graph[j].w;
            if( dis[src][ns]!=oo && dis[src][ns]+nw < dis[src][ne])
            {
                dis[src][ne] = dis[src][ns] + nw;
                reach[src][ne] = false;
                change=true;
            }
        }
        if(!change)
            break;
    }
}
int main()
{
    int t,q,ls,le,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&q);
        graph = new edge[m];
        reach = new bool*[n];
        visit = new bool[n];
        dis = new int*[n];
        //memset(reach,1,sizeof(reach));
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++)
        {
            dis[i] = new int[n];
            reach[i] = new bool[n];
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            graph[i].s =a;
            graph[i].e = b;
            graph[i].w =c;
        }
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&ls,&le);
            if(!visit[ls])
            {
                bellman_ford(ls);
            }
            if(!reach[ls][le])
            {
                printf("No\n");
            }
            else
            {
                if(dis[ls][le]==oo)
                {
                    printf("No\n");
                }
                else
                    printf("%d\n",dis[ls][le]);
            }
        }
        delete[] visit;
        delete[] graph;
        for(int i=0;i<n;i++)
        {
            delete[] dis[i];
            delete[] reach[i];
        }
        delete[] reach;
        delete[] dis;
    }
    return 0;
}
