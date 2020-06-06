#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int n,m,i,j;
    long long int arr[]= {};
    while(cin>>n>>m)
    {
        int counter=0;
        long long int cn1=m;
        for(i=0;; i++)
        {
            if(n%cn1==0)
            {
                cout<<"counter:"<<counter<<endl;
                cout<<n<<" ";
                arr[counter]=n;
                if(n==m)
                {
                    arr[counter]=1;
                    for(j=0;j<=counter;j++)
                        cout<<arr[j]<<" "<<endl;
                    break;
                }
                n=n/cn1;
                counter++;
            }
            else
            {
                cout<<"Boring!"<<endl;
                break;
            }
        }

    }
    return 0;
}
