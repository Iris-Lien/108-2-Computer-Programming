#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int cases;
    int player;
    float p,ans;
    int win_player;
    int round=100;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        cin>>player>>p>>win_player;
        float q = 1 - p;
        ans = (pow(q,win_player-1)*p)*(1-pow(pow(q,player),round))/(1-pow(q,player));
        cout<<ans;
    }

    return 0;
}
