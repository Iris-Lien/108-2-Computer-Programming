#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int i,n;
    vector<string> vs;
    string is1;

    cin>>n;
    getline(cin,is1);
    getline(cin,is1);

    while(n--)
    {
        vs.clear();
        double sum=0,count=1,p;

        while(getline(cin,is1)&&is1!="")
        {
            vs.push_back(is1);
        }

        sort(vs.begin(),vs.end());
        sum=vs.size();

        for(i=0; i<sum; i++)
        {
            if(vs[i]==vs[i+1])
            {
                count++;
            }
            else if(vs[i]!=vs[i+1])
            {
                p=(count/sum)*100;
                cout<<fixed<<setprecision(4);
                cout<<vs[i]<<" "<<p<<endl;
                count=1;
            }
        }

        if(n!=0)
        {
            cout<<endl;
        }
    }
    return 0;
}
