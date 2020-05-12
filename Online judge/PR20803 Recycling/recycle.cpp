#include<iostream>
using namespace std;

inline int funtion(char* arr,int x)
{
    int ans[x];
    for(int i=0; i<x; i++)
        ans[i]=0;
    for(int c=0; c<x; c++)
    {
        for(int j=0; j<5; j++)
        {
            for(int i=0; i<x; i++)
            {
                if(c==i)
                    continue;
                if(arr[c*19+2+4*j]==arr[i*19+2+4*j])
                    ans[c]++;
            }
        }
    }
    int p=0;
    for(int i=0,t=0; i<x; i++)
    {
        if(ans[i]>t)
        {
            t=ans[i];
            p=i;
        }
    }
    return p+1;
}
int main()
{
    char arr[100][19]= {{'\0'},{'\0'}};
    int x=0;
    char cpare[5]= {'r','o','y','g','b'};
    while(cin>>arr[x])
    {
        char temp[3]= {'\0'};
        int t=0;
        if(arr[x][0]=='#')
            break;
        if(arr[x][0]=='e')
        {
            cout<<funtion(&arr[0][0],x)<<'\n';
            for(int i=0; i<=x; i++)
            {
                for(int j=0; j<19; j++)
                    arr[i][j]='\0';
            }
            x=0;
            continue;
        }
        for(int i=0; i<5; i++)
        {
            if(cpare[i]!=arr[x][4*i])
            {
                for(int j=0; j<3; j++)
                    temp[j]=arr[x][4*i+j];
                for(int j=0; j<5; j++)
                {
                    if(cpare[i]==arr[x][4*j])
                    {
                        arr[x][4*i]=arr[x][4*j];
                        arr[x][4*i+2]=arr[x][4*j+2];
                        arr[x][4*j]=temp[0];
                        arr[x][4*j+2]=temp[2];
                        break;
                    }
                }
            }
        }
        x++;
    }

}
