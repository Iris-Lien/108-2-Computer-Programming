#include<iostream>

using namespace std;

void trigular(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
    for(int i=n-1; i>0; i--)
    {
        for(int j=i; j>0; j--)
        {
            cout<<i;
        }
        cout<<endl;
    }
}

int main()
{
    int cases;
    int amplitude,frequency;
    char temp[1];

    cin>>cases;
    cin.getline(temp,1);

    for(int i=0; i<cases; i++)
    {
        cin>>amplitude;
        cin>>frequency;
        trigular(amplitude);
        for(int j=1; j<frequency; j++)
        {
            cout<<endl;
            trigular(amplitude);
        }
        cout<<endl;
    }
    return 0;
}
