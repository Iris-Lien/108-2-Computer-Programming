#include<iostream>

using namespace std;

int main()
{
    int cases,first;
    char a[1];
    while(cin>>cases)
    {
        while(cases--)
        {
            cin.getline(a,1);
            char destination[2];
            for(int k=0; k<2; k++)
            {
                cin>>first;
                char flight[3][first];
                char temp[first];

                for(int i=0; i<first; i++)
                    for(int j=0; j<2; j++)
                        cin>>flight[i][j];

                /*for(int i=0; i<first; i++)
                    for(int j=0; j<2; j++)
                        cout<<flight[i][j];
                */

                char start = flight[0][0];
                char endd = flight[0][1];
                int i=1;

                while(true)
                {
                    if(i==first-1 && flight[first-1][0]!= endd)
                    {
                        destination[k] = endd;
                        //cout<<k<<" "<<destination[k]<<endl;
                        break;
                    }
                    else
                    {
                        if(flight[i][0]==endd)
                        {
                            endd=flight[i][1];
                            i=1;
                            //cout<<"end "<<endd<<endl;
                        }
                        else
                            i++;
                    }
                }

            }
            if(destination[0] == destination[1])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }


    return 0;
}
