#include <bits/stdc++.h>

using namespace std;

bool bpm[505][505];
bool seen[505];
int x,y;
int matchR[505];
bool match(int u)
{
    for(int v=0;v<y;v++)
    {
        if( bpm[u][v] && !seen[v] )
        {
            seen[v] =true;
            if (matchR[v] < 0 || match(matchR[v]))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
int max_match()
{
    fill_n(matchR,y,-1);
    int ans(0);
    for(int i=0;i<x;i++)
    {
        memset(seen,0,sizeof(seen));
        if(match(i))
            ans++;
    }
    return ans;
}
int main()
{
    int t,m,a,b;
    scanf("%d",&t);
    while(t--)
    {
        memset(bpm,0,sizeof(bool)*505*505);
        scanf("%d%d%d",&x,&y,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            bpm[a][b] = true;
        }
        cout<<max_match()<<endl;
    }
    return 0;
}
