#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long hashmat,opponent;
    while(!cin.eof())
    {
        cin>>hashmat>>opponent;
        cout<<abs(opponent-hashmat)<<endl;
    }
    return 0;
}
