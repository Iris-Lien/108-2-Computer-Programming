#include <iostream>

using namespace std;

int main()
{
    int cases;

    while(cin>>cases)
    {
        while(cases--)
        {
            int counter=0;
            int number;
            cin>>number;
            int arr[number];
            for(int i=0; i<number; i++)
                cin>>arr[i];
            for(int i=0; i<number-1; i++)
            {
                for(int j=0; j<number-1; j++)
                {
                    if(arr[j]>arr[j+1])
                    {
                        int temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                        counter++;
                    }
                }
            }
            /*for(int i=0; i<number; i++)
                cout<<arr[i]<<endl;*/
            cout<<"Optimal train swapping takes "<<counter<<" swaps."<<endl;
        }
    }

    return 0;
}
