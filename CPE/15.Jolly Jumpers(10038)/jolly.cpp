#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    int number[3000]= {0};
    int jolly[3000]= {0};

    cin>>n;
    int flag=1;

    for(int i=1; i<=n; i++)
        cin>>number[i];

    for(int i=1; i<=n-1; i++)
    {
        int temp=abs(number[i+1]-number[i]);

        if(temp>=1 && temp<n)
        {
            jolly[temp]++;
            //cout<<temp<<" "<<jolly[temp]<<endl;
        }
        else
            flag=0;
    }
    for(int j=1; j<=n-1; j++)
    {
        if(jolly[j]==0||jolly[j]>1)
            flag=0;
         //cout<<j<<" "<<jolly[j]<<endl;
    }
    if(flag==1)
        cout<<"Jolly";
    else
        cout<<"Not jolly";



    return 0;
}
