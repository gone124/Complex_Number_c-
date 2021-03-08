// problem link : https://www.codechef.com/problems/COTH003
#include<bits/stdc++.h>
using namespace std;
typedef complex<double> P;// point
#define X real()
#define Y imag()
#define N 100
int n;
vector<P> v(N);
vector<P> ans[N];
map<pair<double,double>,int> vis;
bool comp(const P &a,const P b)
{
    if(a.X==b.X)
    return a.Y < b.Y;
    else
    return a.X < b.X;
}
bool cw(P a,P b,P c)
{
    return (conj(c-a)*(c-b)).Y <= 0;
}
bool ccw(P a,P b,P c)
{
    return (conj(c-a)*(c-b)).Y > 0;
}
bool ccw1(P a,P b,P c)
{
    return (conj(c-a)*(c-b)).Y >= 0;
}
void convex_hull(vector<P> &v,int layer)
{
    sort(v.begin(),v.end(),comp);
    P p1=v[0],p2=v.back();
    vector<P> up,down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)v.size(); i++) {
        if (i == v.size() - 1 || cw(p1, v[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], v[i]))
                up.pop_back();
            up.push_back(v[i]);
        }
        if (i == v.size() - 1 || ccw(p1, v[i], p2)) {
            while(down.size() >= 2 && !ccw1(down[down.size()-2], down[down.size()-1], v[i]))
                down.pop_back();
            down.push_back(v[i]);
        }
    }
    vector<P> temp;
    //cout<<up.size()+down.size()-2<<"\n";
    for (int i = 0; i < (int)up.size(); i++)
    {
        temp.push_back(up[i]);
        vis[{up[i].X,up[i].Y}]--;
    }
      //  cout<<"\n";
    for (int i = down.size() - 2; i > 0; i--)
    {
        temp.push_back(down[i]);
        vis[{down[i].X,down[i].Y}]--;
    }
    float may=-100;
    float max=-100;
    int index;
    // starting from topmost point of given convex hull and printing points in anticlockwise order
    for(int i=0;i<temp.size();i++)
    {
        if(may<temp[i].Y)
        {
            may=temp[i].Y;
            index=i;
        }
        else if(may==temp[i].Y)
        {
            if(max<temp[i].X)
            {
                max=temp[i].X;
                index=i;
            }
        }
    }
    for(int i=index;i>=0;i--)
    ans[layer].push_back(temp[i]);
    for(int i=temp.size()-1;i>index;i--)
    ans[layer].push_back(temp[i]);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<N;i++)
        ans[i].clear();
        vis.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            double x,y;
            cin>>x>>y;
            v[i]={x,y};
            vis[{x,y}]++;
        }
        vector<P> temp;
        int layer=0;
        for(int i=0;i<n;i++)
        {
            if(vis[{v[i].X,v[i].Y}]>0)
            {
                temp.clear();
                for(int j=i;j<n;j++)
                {
                    if(vis[{v[j].X,v[j].Y}]>0)
                    temp.push_back(v[j]);
                }
                convex_hull(temp,layer);
                layer++;
            }
        }
        for(int i=0;i<layer;i++)
        {
            for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j].X<<" "<<ans[i][j].Y<<" ";
            //cout<<"\n";
        }
        cout<<"\n";
    }
}

