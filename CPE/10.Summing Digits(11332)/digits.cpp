#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        if(n == 0)
            break;
        while(n/10)
            n = n/10+n%10;
        cout<<n<<endl;
    }

    return 0;
}
