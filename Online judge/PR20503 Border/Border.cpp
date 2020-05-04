#include<iostream>
using namespace std;

int main()
{
    int i, j, k, x, y, l;
    int n;
    char mapp[32][32];
    char str[10000];

    cin>>n;
    for(j=0;j<n;j++)
    {
        cout<<"Bitmap #"<<j+1<<endl;
        cin>>x>>y;

        for(k=0;k<32;k++)
            for(i=0;i<32;i++)
                mapp[k][i]='.';

        cin.getline(str,1000);
        cin.getline(str,1000);

        for(k=0;str[k]!='.';k++)
        {
            switch(str[k])
            {
            case 'N':
                mapp[y][x]='X';
                y++;
                break;
            case 'E':
                mapp[y-1][x]='X';
                x++;
                break;
            case 'W':
                mapp[y][x-1]='X';
                x--;
                break;
            case 'S':
                mapp[y-1][x-1]='X';
                y--;
                break;
            }
        }

        for(k=31;k>=0;k--)
        {
            for(i=0;i<32;i++)
                cout<<mapp[k][i];
            cout<<endl;
        }
        cout<<endl;
    }
}
