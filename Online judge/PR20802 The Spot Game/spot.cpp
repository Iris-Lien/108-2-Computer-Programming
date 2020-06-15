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
            board[i][j]=tmp[i][j];  //�����᪺�}�C�\���쥻��
            tmpstr+=tmp[i][j]+'0';  //tmpstr�O�N�}�C�ন�r��s,��K�M�䦳�S���ۦP���ѧ��X�{
        }
    }
    str=tmpstr;
}
int main()
{
    int n;
    while(cin>>n && n!=0)
    {
        memset(board,0,sizeof(board));	//�Nboard��l�Ƭ�0
        map<string,int> save;	//�����ѧ�
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
                if(save[str]<i+1 && save[str]!=0)   //�p�G��쭫�ƪ��ѧ�
                {
                    move=i; //���ʴX�B
                    flag=true;  //��쭫�ƪ��ѧ�,break
                    break;
                }
                else
                    save[str]=i+1;  //�p�G�S����쭫�ƪ��ѧ��N���B��+1
                Rotate(str,n);	//�������A�~��M�䦳�S���X�{�ۦP���ѧ�
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
