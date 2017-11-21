#include <bits/stdc++.h>

using namespace std;

struct node
{
    int rating,crating;
    vector<int> child;
};
node tree[1005];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        tree[i].child.clear();
    }
}
void dp(int root)
{
    if(tree[root].child.size()==0)
    {
        tree[root].crating = 0;
        return;
    }
    else
    {
        int uv(0),ev(0);
        for(int i=0;i<tree[root].child.size();i++)
        {
            int x = tree[root].child[i];
            dp(x);
            uv += tree[x].rating;
            ev += tree[x].crating;
        }
        tree[root].rating = max(uv,ev+tree[root].rating);
        tree[root].crating = uv;
        return;
    }
}
int main()
{

    int n,t,r,s,root;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&r);
        init(n);
        tree[1].rating = r;
        tree[1].crating = 0;
        for(int i=2;i<=n;i++)
        {
            scanf("%d%d",&s,&r);
            tree[s].child.push_back(i);
            tree[i].rating = r;
            tree[i].crating = 0;
        }
        dp(1);
        printf("%d\n",tree[1].rating);
    }
    return 0;
}
