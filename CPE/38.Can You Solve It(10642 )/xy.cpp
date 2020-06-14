#include <iostream>

using namespace std;

int main()
{
    int T,x1,y1,x2,y2;
    while (cin>>T)
        for (int t = 1 ; t <= T ; t++)
        {
            cin>>y1>>x1>>y2>>x2;

            long long n = (x1+y1)*(x1+y1+(long long)1)/(long long)2+y1;
            long long m = (x2+y2)*(x2+y2+(long long)1)/(long long)2+y2;

            cout<<"Case "<<t<<": "<<m-n<<endl;

        }
    return 0;

}
