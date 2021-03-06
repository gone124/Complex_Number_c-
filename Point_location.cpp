#include<bits/stdc++.h>
using namespace std;
typedef complex<double> P;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        P  a = {x1,y1} , b={x2,y2} , c={x3,y3} , d=conj(c-a)*(c-b);
        if(d.imag()==0)
        cout<<"TOUCH\n";
        else if(d.imag()>0)
        cout<<"LEFT\n";
        else
        cout<<"RIGHT\n";
    }
}
