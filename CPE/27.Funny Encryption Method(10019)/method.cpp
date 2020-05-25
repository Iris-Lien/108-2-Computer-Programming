#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int bits( int a )
{
    int count = 0;
    while ( a )
    {
        count += a%2;
        a >>= 1;
    }
    return count;
}

int main()
{
    int n,m,b1,b2;
    while ( cin>>n )
    {
        while ( n -- )
        {
            cin>>m;
            b1 = bits( m );
            b2 = 0;
            while ( m )
            {
                b2 += bits( m%10 );
                m /= 10;
            }
            cout<<b1<<" "<<b2<<endl;
        }
    }
    return 0;
}
