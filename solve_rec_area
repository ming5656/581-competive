#include <bits/stdc++.h>

using namespace std;
#define ll long long
struct edge
{
    int x,lowy,upy;
    bool open;
    edge(int rx,int y1,int y2,bool op)
    {
        x = rx;
        lowy = y1;
        upy = y2;
        open = op;
    }
    bool operator <(const edge& b)const
    {
        return x < b.x;
    }
};
int n,m, *h,num;
int *sum, *counter;
vector<edge> es;

void update(int p,int l,int r,int miny,int maxy,bool op)
{
    if(h[r]<miny || maxy <h[l])
    {
       /*cout<<h[r]<<" "<<h[l]<<endl;
    cout<<miny<<" "<<maxy<<endl;*/
        return;
    }
    int c = p<<1,mid = (l+r)>>1;
    if(miny<=h[l]&&h[r]<=maxy)
    {
        if(op)
        {
            counter[p]++;
        }
        else
        {
            counter[p]--;
        }
        if(counter[p])
        {
            sum[p] = h[r]- h[l];
        }
        else
        {
            sum[p] = sum[c] +sum[c+1];
        }
        return;
    }
    if(l+1>=r)
        return;
    update(c,l,mid,miny,maxy,op);
    update(c+1,mid,r,miny,maxy,op);
    if(counter[p])
    {
        sum[p] = h[r] - h[l];
    }
    else
    {
        sum[p] = sum[c] + sum[c+1];
    }
}
ll solve()
{
    sort(h+1,h+m+1);
    int k =1;
    for(int i=2;i<=m;i++)
    {
        if(h[i]!=h[k])
        {
            h[++k] = h[i];
        }
    }
    m = k;
    for(int i=0,lm = num << 4 ; i<lm ; i++)
    {
        sum[i] = 0;
        counter[i] = 0;
    }
    ll area(0);
    sort(es.begin(),es.end());
    update( 1 , 1 , m , es[0].lowy , es[0].upy , es[0].open);
    for(int i=1;i<es.size();i++)
    {
        area += sum[1]*(es[i].x - es[i - 1].x);
        //cout<<sum[1]<<endl;
        update(1, 1, m, es[i].lowy, es[i].upy, es[i].open);
    }
    return area;
}
int main()
{
    int t,x1, y1, x2, y2;;
    scanf("%d",&t);
    while(t--)
    {
        m = 0;
        scanf("%d",&num);
        h = new int[num*3];
        sum = new int[num*33];
        counter = new int[num*33];
        for(int i=1;i<=num;i++)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(y1>y2)
                swap(y1,y2);
            if(x1>x2)
                swap(x1,x2);
  //          x2++;
    //y2++;
            es.push_back(edge(x1, y1, y2, true));
            es.push_back(edge(x2, y1, y2, false));
            h[++m] = y1;
            h[++m] = y2;
        }
        printf("%lld\n",solve());
        delete []sum;
        delete []counter;
        delete []h;
        es.clear();
    }
    return 0;
}
