#include<iostream>
#include <algorithm>
#include<cmath>

using namespace std;
int main()
{
    int cases;
    int n;
    int x,y;
    int x_array[30000],y_array[8848];
    int x_max,y_max;

    int length=0;

    cin>>cases;

    int i,j;
    for(i=0;i<cases;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>x>>y;
            x_array[j]=x;
            y_array[j]=y;
            //cout<<x_array[j]<<y_array[j]<<endl;
            for(int a=0;a<n-1;a++)
            {
                for(int b=0;b<n-1;b++)
                {
                    if(x_array[b]>x_array[b+1])
                    {
                        int x_temp;
                        x_temp=x_array[b];
                        x_array[b]=x_array[b+1];
                        x_array[b+1]=x_temp;

                        int y_temp;
                        y_temp=y_array[b];
                        y_array[b]=y_array[b+1];
                        y_array[b+1]=y_temp;
                    }
                }
            }
            for(int a=0;a<n;a++)
                cout<<x_array[a]<<endl;

            int max=0;
            for(int a=0;a<n;a++)
            {
                if(y_array[a]>max)
                    max=y_array[a]; //the highest point if y-coordinate
            }
            //cout<<max<<endl;
            for(int a=n;a>=max;a--)
            {
                if(y_array[a-1]>y_array[a])
                {
                    float slope;
                    float x;
                    slope=(y_array[a-1]-y_array[a])/(x_array[a]-x_array[a-1]);
                    //x-x_array[a-1]=slope*(y_array[a-1]-y_array[a])
                    x=slope*(y_array[a-1]-y_array[a])+x_array[a-1];
                    length+=sqrt((x-x_array[a-1])*(x-x_array[a-1])+(y_array[a-1]-y_array[a])*(y_array[a-1]-y_array[a]));
                }
            }
            //cout<<length;
        }
    }
    return 0;
}
