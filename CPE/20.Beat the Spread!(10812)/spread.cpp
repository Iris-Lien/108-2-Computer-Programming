#include<iostream>

using namespace std;

int main()
{
    int cases;
    int s, d;
    float a, b;

    cin>>cases;
    for(int i=1;i<=cases;i++)
    {
        cin>>s>>d;
        if(s<d)
            cout<<"impossible"<<endl;
        else
        {
            a = (s+d)/2;
            b = (s-d)/2;
            if((a<0)||(b<0))
                cout<<"impossible"<<endl;
            else if(((s+d)%2!=0) || ((s-d)%2!=0))
                cout<<"impossible"<<endl;
            else
                cout<<a<<" "<<b<<endl;
        }
    }
    return 0;
}
