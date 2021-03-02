#include<bits/stdc++.h>
using namespace std;
typedef complex<double> P;// point
#define X real()
#define Y imag()
int main()
{
    // dot product of two vectors if given by (conj(a)*b).X while cross product is given by (conj(a)*b).Y
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    P a={x1,y1};
    P b={x2,y2};
    P c=conj(a)*b;
    int dot_product = c.X;
    int cross_product = c.Y;
    cout<<dot_product<<" "<<cross_product<<"\n";
}
