#include<iostream>
using namespace std;

int main()
{
    int cases;
    int a,b;

    cin>>cases;
    for(int i=1; i<=cases; i++)
    {
        int sum=0;
        int evensum=0;
        int oddsum=0;
        cin>>a>>b;
        if(a>b)
        {
            int temp;
            temp=a;
            a=b;
            b=temp;
        }
        for(int j=a;j<=b; j++)
        {
            sum+=j;
            if(j%2==0)
                evensum+=j;
        }
        //cout<<sum<<endl;
        //cout<<evensum<<endl;
        oddsum=sum-evensum;
        cout<<"Case "<<i<<": "<<oddsum<<endl;
    }


    return 0;
}
