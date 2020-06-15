#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<string.h>
using namespace std;
int board[55][55];
void Rotate(string &str,int n)  //做陣列順時針旋轉90度
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
            board[i][j]=tmp[i][j];  //把旋轉後的陣列蓋掉原本的
            tmpstr+=tmp[i][j]+'0';  //tmpstr是將陣列轉成字串存,方便尋找有沒有相同的棋局出現
        }
    }
    str=tmpstr;
}
int main()
{
    int n;
    while(cin>>n && n!=0)
    {
        memset(board,0,sizeof(board));	//將board初始化為0
        map<string,int> save;	//紀錄棋局
        int player=2,ansp,move;
        bool flag=false;
        for(int i=0; i<2*n; i++)
        {
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            if(flag==true)
                continue;
            if(ch=='+') //放石頭標記1
            {
                board[a-1][b-1]=1;
            }
            else if(ch=='-')    //拿石頭標記0
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
                if(save[str]<i+1 && save[str]!=0)   //如果找到重複的棋局
                {
                    move=i; //移動幾步
                    flag=true;  //找到重複的棋局,break
                    break;
                }
                else
                    save[str]=i+1;  //如果沒有找到重複的棋局就讓步數+1
                Rotate(str,n);	//做旋轉後再繼續尋找有沒有出現相同的棋局
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
