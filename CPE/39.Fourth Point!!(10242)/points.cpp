#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i,t;
    double x[4],y[4],ax,ay;

    while(cin>>x[0]>>y[0])
    {
        ax=x[0];
        ay=y[0];

        for(i=1; i<4; i++) //input
        {
            cin>>x[i]>>y[i];
            ax+=x[i];   //add all x, y points
            ay+=y[i];
        }

        for(i=0; i<4; i++)
        {
            for(t=i+1; t<4; t++)
            {
                if(x[i]==x[t]&&y[i]==y[t]) //find another same point
                {
                    cout<<fixed<<setprecision(3);
                    cout<<ax-3*x[i]<<" ";   //output x, y point
                    cout<<ay-3*y[i]<<endl;
                }
            }
        }
    }
    return 0;
}
