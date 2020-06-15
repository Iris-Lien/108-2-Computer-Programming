#include<iostream>

using namespace std;

int GCD(int x, int y)
{
    int r = 0;
    while(y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    int N;
    int i, j;
    while(cin>>N && N!=0)
    {
        int G=0;
        for(i=1; i<N; i++)
            for(j=i+1; j<=N; j++)
            {
                G+=GCD(i,j);
            }
        cout<<G<<endl;
    }


    return 0;
}
