#include<iostream>
using namespace std;
void Bangla( long long int n )
{
    if( n == 0 )
        return;

    if( n/10000000 )
    {
        Bangla( n/10000000 );
        cout<<" kuti";
        n %= 10000000;
    }

    if( n/100000 )
    {
        Bangla( n/100000 );
        cout<<" lakh";
        n %= 100000;
    }

    if( n/1000 )
    {
        Bangla( n/1000 );
        cout<<" hajar";
        n %= 1000;
    }

    if( n/100 )
    {
        //764
        Bangla( n/100 );
        cout<<" shata";
        n %= 100;
    }

    if( n )
        cout<<" "<<n;
}

int main()
{
    long long n;
    int cases = 1;//½s¸¹
    while(cin >> n)
    {
        cout<<cases<<".";
        if(n==0)
        {
            cout<<" 0"<<endl;
            cases++;
        }
        else
        {
            Bangla( n );
            cases++;
            cout<<endl;
        }
    }
    return 0;
}
