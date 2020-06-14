#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<string.h>
using namespace std;
int board[55][55];
void Rotate(string &str,int n)  //���}�C���ɰw����90��
{
    int tmp[55][55];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            tmp[j][n-i-1]=board[i][j];
        }
    }
    string tmpstr;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            board[i][j]=tmp[i][j];
            tmpstr+=tmp[i][j]+'0';
        }
    }
    str=tmpstr;
}
int main()
{
    int n;
    while(cin>>n && n!=0)
    {
        memset(board,0,sizeof(board));
        map<string,int> save;
        int player=2,ansp,move;
        bool flag=false;
        for(int i=0; i<2*n; i++)
        {
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            if(flag==true)
                continue;
            if(ch=='+') //����Y�аO1
            {
                board[a-1][b-1]=1;
            }
            else if(ch=='-')    //�����Y�аO0
            {
                board[a-1][b-1]=0;
            }

            string str;
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    str+=board[j][k]+'0';
                }
            }
            for(int j=0; j<4; j++)
            {
                if(save[str]<i+1 && save[str]!=0)
                {
                    move=i;
                    ansp=player;
                    flag=true;
                    break;
                }
                else
                    save[str]=i+1;
                Rotate(str,n);
            }
            if(flag==true)
                continue;

            if(player==2)
                player=1;
            else
                player=2;
        }
        if(flag==true)
            cout<<"Player "<<player<<" wins on move "<<move+1<<endl;
        else
            cout<<"Draw"<<endl;
    }
    return 0;

}
