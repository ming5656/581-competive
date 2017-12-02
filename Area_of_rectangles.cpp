// O(n^2) 
//TLE
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    int x1,x2,y1,y2;
    bool operator <(const point& b)const
    {
        if(x2==b.x2)
        {
            return x1<b.x1;
        }
        return x2<b.x2;
    }
};
struct range
{
    int up,low;
    range(int l,int r)
    {
        low = min(l,r);
        up = max(l,r);
    }
    bool isOverlapping(range& b)
    {
        return !(low > b.up || up < b.low);
    }
    void combine(range& b)
    {
        if(isOverlapping(b))
        {
            up = max(up,b.up);
            low = min(low,b.low);
        }
    }
};
void insertY(vector<range>& y,range ry)
{
    vector<range>::iterator it = y.begin();
    while(it!=y.end())
    {
        if(ry.isOverlapping(*it))
        {
            ry.combine(*it);
            vector<range>::iterator c = it;
            if(c == y.end()-1)
            {
                y.erase(c);
                break;
            }
            else
            {
                y.erase(c);
                ++it;
            }
        }
        else
            ++it;
    }
    y.push_back(ry);
}
void getRangeOfY(vector<point>& rec,vector<point>::iterator it,range& x,vector<range>& y)
{
    for(;it!=rec.end();it++)
    {
        /*if(x.up <= it->x1)
            break;
        else*/ if(x.low < it->x2 && x.up > it->x1)
        {
            insertY(y,range(it->y1,it->y2));
        }
    }
}
ll getRecArea(range rangeX,vector<range>& rangeY)
{
    ll w = rangeX.up - rangeX.low;
    ll area(0);
    for(int i=0;i < rangeY.size();i++)
    {
        //cout<<rangeY[i].up<<" "<<rangeY[i].low<<endl;
        area += (w *(rangeY[i].up - rangeY[i].low));
    }
    return area;
}
ll getArea(vector<point>& rec)
{
    sort(rec.begin(),rec.end());
    vector<int> x;
    vector<point> ::iterator recit;
    for(recit = rec.begin();recit != rec.end();recit++)
    {
        x.push_back(recit->x1);
        x.push_back(recit->x2);
    }
    sort(x.begin(),x.end());
    ll area(0);
    vector<int> :: iterator xit;
    for(xit = x.begin(),recit = rec.begin();xit != x.end() && xit != x.end()-1 ;xit++)
    {
        vector<int> :: iterator nxit = xit + 1 ;
        if(*xit < *nxit )
        {
            range rangeX(*xit,*nxit);
            while(recit->x2 < *xit)
            {
                recit++;
            }
            vector<range> rangeY;
            getRangeOfY(rec,recit,rangeX,rangeY);
            area += getRecArea(rangeX,rangeY);
        }
    }
    return area;
}
int main()
{
    int t,n;
    vector<point> input;
    scanf("%d",&t);
    while(t--)
    {
        input.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            point buffer;
            scanf("%d%d%d%d",&buffer.x1,&buffer.y1,&buffer.x2,&buffer.y2);
            if(buffer.x1 > buffer.x2)
            {
                int tmp = buffer.x1;
                buffer.x1 = buffer.x2;
                buffer.x2 = tmp;
            }
            if(buffer.y1 > buffer.y2)
            {
                int tmp = buffer.y1;
                buffer.y1 = buffer.y2;
                buffer.y2 = tmp;
            }
            input.push_back(buffer);
        }
        printf("%lld\n",getArea(input));
    }
    return 0;
}
