#include<iostream>
#include <cmath>    //cos,sqrt
#include <iomanip>  //setprecision

using namespace std;

int main()
{
    double s, a;
    double PI = 2*acos(0);

    string str;
    while(cin>>s>>a>>str)
    {
        double earth=6440;
        double arc_distance, chord_distance=0;
        if(a > 180.0)
            a = 360.0 - a;
        if(str == "min")
            a /= 60.0; //degree=min/60

        chord_distance = (earth+s) * cos((90.0 - a/2.0)/ 180.0 * PI) * 2.0;
        arc_distance = 2.0 * PI * (earth+s) * a/360.0;

        cout<<fixed<<setprecision(6)<<arc_distance
            <<" "<<chord_distance<<endl;
    }

    return 0;
}
