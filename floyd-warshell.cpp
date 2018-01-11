#include <bits/stdc++.h>

#define oo 99999999
using namespace std;

int graph[1000][1000];

void floyd_warshall(int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][k]+graph[k][j]<graph[i][j])
                {
                    graph[i][j] = graph[i][k]+graph[k][j];
                }
            }
        }
    }
}
int main()
{
    int t,n,m,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        vector<int> sum;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            fill_n(graph[i],n,oo);
            graph[i][i]=0;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            graph[u][v] = w;
        }
        floyd_warshall(n);
        for(int i=0;i<n;i++)
        {
            int v(0);
            bool reach = true;
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]<oo)
                {
                    v+=graph[i][j];
                }
                else
                    reach = false;
            }
            if(reach)
                sum.push_back(v);
            else
                sum.push_back(oo);
        }
        int ans(0),minv = sum[0];
        for(int i=1;i<n;i++)
        {
            if(minv > sum[i])
            {
                minv = sum[i];
                ans = i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
