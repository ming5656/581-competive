#include <bits/stdc++.h>

using namespace std;

struct interval
{
    int s,t;
};
int main()
{
    int n;
    multiset<int> tree;
    interval r[250005];
    while(scanf("%d",&n)&&n)
    {
        tree.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&r[i].s,&r[i].t);
        }
        int ans(0);
        for(int i=0;i<n;i++)
        {
            tree.insert(r[i].s);
            int g = r[i].t ;
            multiset<int>::iterator it = tree.upper_bound(g);
            if(it != tree.end())
            {
                tree.erase(it);
            }

        }
        cout<<tree.size()<<endl;
    }
    return 0;
}
