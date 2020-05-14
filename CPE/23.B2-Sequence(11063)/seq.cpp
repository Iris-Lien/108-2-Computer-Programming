#include<iostream>

using namespace std;

int main()
{
    int n;
    int counter=1;
    while(cin>>n)
    {
        int a[n];
        int b[20001]= {0};
        int flag=0;
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                int result = a[i]+a[j];
                if(a[i]>a[j] || b[result]!=0)
                {
                    flag=1;
                    break;
                }
                else
                    b[result]++;
            }
        }
        if(flag==0)
            cout<<"Case #"<<counter<<": It is a B2-Sequence."<<endl;
        else
            cout<<"Case #"<<counter<<": It is not a B2-Sequence."<<endl;
        counter++;
        cout<<endl;
    }
}
