#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int n,l;
    cin>>n;
    char c1, c2;
    long long int i, j, cn;
    cn = 1;
    while(cn<=n)
    {
        cin>>c1>>c2;
        cin>>l;
        long long int N[l][l];
        long long int flag = 0;
        for(i=0; i<l; i++)
        {
            for(j=0; j<l; j++)
            {
                cin>>N[i][j];
            }
        }
        for(i=0; i<l; i++)
        {
            for(j=0; j<l; j++)
            {
                if(N[i][j] != N[(l-1-i)][(l-1-j)])
                    flag = 1;
                if(N[i][j] < 0)
                    flag = 1;
            }
        }
        if(flag == 0)
            cout<<"Test #"<<cn<<": Symmetric."<<endl;
        else
            cout<<"Test #"<<cn<<": Non-symmetric."<<endl;
        cn++;
    }
}
