#include <bits/stdc++.h>

using namespace std;

int matrix[505][505],rrow[505],lrow[505],rcol[505],lcol[505];
int kadne(int num[],int len)
{
    int sum(0),e(-1),ans(0),maxv = -999999;
    for(int i=0;i<len;i++)
    {
        maxv=max(maxv,num[i]);
        sum+=num[i];
        if(sum<0)
        {
            sum = 0;
            continue;
        }
        //ans = max(ans,sum);
        if(ans<sum||(ans==sum&&num[i]==0))
        {
            e=i;
            ans=sum;
        }
    }
    if(e==-1)
    {
        return maxv;
    }
    return ans;
}
int maxrec(int n)
{
    //memset(rrow,0,sizeof(rrow));
    //memset(lrow,0,sizeof(lrow));
    fill_n(rrow,505,-999999999);
    fill_n(lrow,505,-999999999);
    int h[n];
    for(int l=0;l<n;l++)
    {
        memset(h,0,sizeof(h));
        for(int r=l;r<n;r++)
        {
            for(int k=0;k<n;k++)
            {
                h[k]+=matrix[r][k];
            }
            int sum= kadne(h,n);
            lrow[l]= max(lrow[l],sum);
            rrow[r] = max(rrow[r],sum);
        }
    }
    fill_n(rcol,505,-999999999);
    fill_n(lcol,505,-999999999);
    for(int l=0;l<n;l++)
    {
        memset(h,0,sizeof(h));
        for(int r=l;r<n;r++)
        {
            for(int k=0;k<n;k++)
            {
                h[k]+=matrix[k][r];
            }
            int sum= kadne(h,n);
            lcol[l]= max(lcol[l],sum);
            rcol[r] = max(rcol[r],sum);
        }
    }
    int ans = -999999999;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            ans = max(rrow[i-1]+lrow[j],ans);
            ans = max(rcol[i-1]+lcol[j],ans);
        }
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&matrix[i][j]);
            }
        }
        int ans= maxrec(n);
        printf("%d\n",ans);
    }
    return 0;
}
