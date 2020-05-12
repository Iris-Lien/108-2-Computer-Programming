#include<iostream>

using namespace std;

int main(void)
{
    int N;
    while(cin>>N)
    {
        if(N==0)
            break;
        char arr[2*N][N][N];
        for(int x=0; x<2*N; x++)
        {
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    arr[x][i][j]='0';
                }
            }
        }

        int move=0, t=0, count[2*N]= {0},determine=0;
        for(int i=0 ; i<2*N ; i++)
        {
            int row,column;
            char oper;
            cin>>row>>column>>oper;
            if(oper=='+')
            {
                for(int c=i; c<2*N; c++)
                    arr[c][N-row][column-1]='x';
                t++;
                count[i]=t;
            }
            if(oper=='-')
            {
                for(int c=i; c<2*N; c++)
                    arr[c][N-row][column-1]='0';
                t--;
                count[i]=t;
            }
            int equal=0;
            for(int j=0; j<i && determine==0; j++)
            {
                equal=0;
                for(int x=0; x<N; x++)
                {
                    for(int y=0; y<N; y++)
                    {
                        if(arr[i][x][y]!=arr[j][x][y])
                            equal++;
                    }
                }
                if(equal==0)
                {
                    move=i;
                    determine=1;
                    break;
                }
            }
            for(int j=0; j<i && determine==0; j++)
            {
                equal=0;
                for(int x=0; x<N; x++)
                {
                    for(int y=0; y<N; y++)
                    {
                        if(arr[i][x][y]!=arr[j][N-1-y][x])
                            equal++;
                    }
                }
                if(equal==0)
                {
                    move=i;
                    determine=1;
                    break;
                }
            }
            for(int j=0; j<i && determine==0; j++)
            {
                equal=0;
                for(int x=0; x<N; x++)
                {
                    for(int y=0; y<N; y++)
                    {
                        if(arr[i][x][y]!=arr[j][N-1-x][N-1-y])
                            equal++;
                    }
                }
                if(equal==0)
                {
                    move=i;
                    determine=1;
                    break;
                }
            }
            for(int j=0; j<i && determine==0; j++)
            {
                equal=0;
                for(int x=0; x<N; x++)
                {
                    for(int y=0; y<N; y++)
                    {
                        if(arr[i][x][y]!=arr[j][y][N-1-x])
                            equal++;
                    }
                }
                if(equal==0)
                {
                    move=i;
                    determine=1;
                    break;
                }
            }
        }
        if(move==0)
            cout<<"Draw\n";
        else
        {
            int x=(move%2==0)?2:1;
            cout<<"Player "<<x<<" wins on move "<<move+1<<endl;
        }
    }
}
