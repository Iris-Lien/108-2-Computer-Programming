#include<iostream>

using namespace std;

int main()
{
    int input_a,input_b;
    int cycle_length;
    while(cin>>input_a>>input_b)
    {
        cout<<input_a<<" "<<input_b<<" ";
        cycle_length = 0;
        if(input_a>input_b)
        {
            int temp=input_a;
            input_a=input_b;
            input_b=temp;
        }

        int i,j;
        for(i=input_a; i<=input_b; i++)
        {
            int temp=1;
            j=i;
            while(j!=1)
            {
                if(j%2!=0)
                {
                    j=3*j+1;
                }
                else
                {
                    j=j/2;
                }
                temp++;
            }
            if(temp>cycle_length)
            {
                cycle_length=temp;
            }
        }
        cout<<cycle_length<<endl;

    }
    return 0;
}
