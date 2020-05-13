#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int a, b;
    int left, right;

    while(cin>>a>>b)
    {
        if(a==0 && b==0)
            break;
        else
        {
            left = sqrt(a);
            right = sqrt(b);
            if(left*left == a)
                cout<<(right-left)+1<<endl;
            if(left*left < a)
                cout<<right-left<<endl;
        }
    }

    return 0;
}
