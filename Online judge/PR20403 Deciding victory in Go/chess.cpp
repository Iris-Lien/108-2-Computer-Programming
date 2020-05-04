#include<iostream>
using namespace std;

int main()
{
    int  n, i, j, k, l, counter;
    int flag;
    int black, white;
    char ch;
    int mapp[9][9];
    cin>>n;
    for(j=0; j<n; j++)
    {
        counter=0;
        for(k=0; k<9; k++)
        {
            for(i=0; i<9; i++)
            {
                cin>>ch;
                if(ch=='O')
                    mapp[k][i]=1000;
                if(ch=='X')
                    mapp[k][i]=2000;
                if(ch=='.')
                {
                    mapp[k][i]=counter;
                    counter++;
                }
            }
        }
        /*for(k=0;k<9;k++)
        {
            for(i=0;i<9;i++)
            {
                cout<<mapp[k][i];
            }
            cout<<endl;
        }*/
        flag =1;
        while(flag)
        {
            flag=0;
            for(k=0; k<9; k++)
            {
                for(i=0; i<9; i++)
                {
                    if(mapp[k][i]<1000)
                    {
                        if(k-1>=0 && mapp[k-1][i]<mapp[k][i])
                        {
                            mapp[k][i]=mapp[k-1][i];
                            flag=1;
                        }
                        if(k+1<9 && mapp[k+1][i]<mapp[k][i])
                        {
                            mapp[k][i]=mapp[k+1][i];
                            flag=1;
                        }
                        if(i-1>=0 && mapp[k][i-1]<mapp[k][i])
                        {
                            mapp[k][i]=mapp[k][i-1];
                            flag=1;
                        }
                        if(i+1<9 && mapp[k][i+1]<mapp[k][i])
                        {
                            mapp[k][i]=mapp[k][i+1];
                            flag=1;
                        }
                    }
                }
            }
        }
        for(l=0; l<81; l++)
        {
            black=0;
            white=0;
            for(k=0; k<9; k++)
            {
                for(i=0; i<9; i++)
                {
                    if(mapp[k][i]==l)
                    {
                        if(k-1>=0 && mapp[k-1][i]==1000)
                            white++;
                        if(k+1<9 && mapp[k+1][i]==1000)
                            white++;
                        if(i-1>=0 && mapp[k][i-1]==1000)
                            white++;
                        if(i+1<9 && mapp[k][i+1]==1000)
                            white++;

                        if(k-1>=0 && mapp[k-1][i]==2000)
                            black++;
                        if(k+1<9 && mapp[k+1][i]==2000)
                            black++;
                        if(i-1>=0 && mapp[k][i-1]==2000)
                            black++;
                        if(i+1<9 && mapp[k][i+1]==2000)
                            black++;
                    }
                }
            }

            if(white==0 && black ==0)
                flag=-1;
            else if(white==0)
                flag=2000;
            else if(black==0)
                flag=1000;
            else
                flag=-1;

            for(k=0; k<9; k++)
                for(i=0; i<9; i++)
                    if(mapp[k][i]==l)
                        mapp[k][i]=flag;
        }
        black=0;
        white=0;
        for(k=0;k<9;k++)
            for(i=0;i<9;i++)
                if(mapp[k][i]==2000)
                    black++;
                else if(mapp[k][i]==1000)
                    white++;
        cout<<"Black "<<black<<" White "<<white<<endl;

        }
    }
