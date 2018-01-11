#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
#define ll long long
using namespace std;

ll mp[10002][10002];
int n,m;
bool combine[10002];
ll minC=oo;

void ss(int &s,int &t){
    bool vis[n];
    int w[n];
    memset(vis,0,sizeof(vis));
    memset(w,0,sizeof(w));
    int tmpj=9999;
    for(int i=0;i<n;i++)
    {
        int maxv=-oo;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&& !combine[j] && maxv<w[j] )
            {
                maxv=w[j];
                tmpj=j;
            }
        }
        if(t==tmpj)
        {
            minC=w[t];
            return;
        }
        vis[tmpj]=true ;
        s=t;
        t=tmpj;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&!combine[j])
                w[j]+=mp[t][j];
        }
    }
    minC=w[t];
}
ll mincut(){
    ll ans =oo;
    int s,t;
    memset(combine,0,sizeof(combine));
    for(int i=0;i<n-1;i++){
        s=t=-1;
        ss(s,t);
        combine[t]=true;
        ans=min(minC,ans);
        for(int j=0;j<n;j++){
            mp[s][j]+=mp[t][j];
            mp[j][s]+=mp[j][t];
        }
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(mp,0,sizeof(mp));
        int u,v;
        ll w;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%lld",&u,&v,&w);
            mp[u][v]+=w;
            mp[v][u]+=w;
        }
        cout<<mincut()<<endl;
    }
    return 0;
}
