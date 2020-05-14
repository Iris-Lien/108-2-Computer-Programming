#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long long int cases;
    long long int n;
    char s1, s2;

    cin>>cases;
    for(long long int k=1; k<=cases; k++)
    {
        cin>>s1>>s2;
        cin>>n;
        long long int matrix[n*n];
        long long int i,j;
        int flag=0;
        for(i=0; i<n*n; i++)
            cin>>matrix[i];

        for(i=0; i<n*n; i++)
        {
            //for(j=0; j<n; j++)
            //{
                if(matrix[i]!=matrix[n*n-1-i] || matrix[i]<0)
                    flag=1;
            //}
        }
        if(flag==0)
            cout<<"Test #"<<k<<": Symmetric."<<endl;
        else
            cout<<"Test #"<<k<<": Non-symmetric."<<endl;
    }
}
