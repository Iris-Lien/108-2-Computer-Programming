#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int cases;
    int i,j,k;
    int temp;
    int relative;


    cin>>cases;
    for(i=0;i<cases;i++)
    {
        int distance=0;
        int mid;
        cin>>relative;
        int array[relative];
        for(j=0;j<relative;j++)
        {
            cin>>array[j];
        }
        for(j=0;j<relative-1;j++)
        {
            for(k=0;k<relative-1;k++)
            {
                if(array[k]>array[k+1])
                {
                    temp=array[k];
                    array[k]=array[k+1];
                    array[k+1]=array[k];
                }
            }
        }
        if(relative%2==0)
            mid=array[(relative/2)-1];
        else
            mid=array[(relative/2)];
        for(j=0;j<relative;j++)
            distance+=abs(mid-array[j]);

        cout<<distance<<endl;

    }

    return 0;
}
