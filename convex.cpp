#include<bits/stdc++.h>
using namespace std;
typedef complex<double> P;// point
#define X real()
#define Y imag()
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
void convex_hull(vector<P> &v)
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
    cout<<up.size()+down.size()-2<<"\n";
    for (int i = 0; i < (int)up.size(); i++)
        cout<<(int)up[i].X<<" "<<(int)up[i].Y<<"\n";
    for (int i = down.size() - 2; i > 0; i--)
        cout<<(int)down[i].X<<" "<<(int)down[i].Y<<"\n";
 
}
int main()
{
    int n;
    cin>>n;
    vector<P> v(n);
    for(int i=0;i<n;i++)
    {
        double x,y;
        cin>>x>>y;
        v[i]={x,y};
    }
    convex_hull(v);
 
}
