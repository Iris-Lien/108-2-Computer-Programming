#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string country[n];

    string name;
    for( int i = 0 ; i < n ; ++i )
    {
        cin >> country[i];
        getline(cin, name);
    }

    sort( country, country+n );

    for( int i = 0 ; i < n ; ++i )
    {
        cout<<country[i]<<" ";

        int counter = 0;
        int j;
        for( j = i ; j < n ; ++j )
        {
            if( country[i] != country[j] )
            {
                break;
            }

            counter++;
        }
        cout<<counter<<endl;;
        i = j-1;
    }

    return 0;
}
