#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
    int x;
    int arr[500000];
    char input[3000], *temp;
    while(cin>>x)
    {
        long long int ans = 0;

        cin.getline(input, 3000);
        cin.getline(input, 3000);
        temp = strtok(input, " ");

        int i=0;
        int counter = 0;    //­pºâ¦¸¤è
        while(temp!=NULL)
        {
            //cout<<temp<<endl;
            arr[i] = atoi(temp);
            temp = strtok(NULL, " ");
            i++;
            counter++;
        }
        //cout<<i<<endl;

        counter -= 2;
        for(int j=0; j<i; j++)
        {
            if(counter>=0)
            {
                //cout<<"counter"<<counter<<endl;
                long long buf = arr[j];
                buf *= (counter + 1);
                //cout<<buf<<endl;
                ans += buf*pow((double)x,(double)counter);
                //cout<<"j:"<<j<<" "<<arr[j]<<endl;
                //cout<<"ans:"<<ans<<endl;
                counter--;
            }

        }
        cout<<ans<<endl;

    }


    return 0;
}
