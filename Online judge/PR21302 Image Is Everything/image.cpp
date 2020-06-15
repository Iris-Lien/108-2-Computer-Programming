#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define REP(i,n) for (int i = 0; i < (n); i++)	//�NREP�w�q��for�j��

const int N = 15;

char view[N][N][N], pos[N][N][N];	//�ŧi�[�ݮɪ�������}�C�M�@�뤻����}�C
int n;

char getChar() //�I���r��
{
    char ch;
    while (true)
    {
        ch = getchar();
        if ((ch >= 'A' && ch <= 'Z') || ch == '.')	//�P�_�O�_���r���ΪŤ�
            return ch;
    }
}

void input()
{
    REP(i, n) REP(k, 6) REP(j, n) view[k][i][j] = getChar();	//�N�[�ݮɪ��C��s�Jview�}�C��
    REP(x, n) REP(y, n) REP(z, n) pos[x][y][z] = '#';	//�Npos�}�C��l�Ƭ�'#'
}

void search(int i, int j, int k, int p, int& x, int& y, int& z)
{
    switch(k)
    {
    case 0:	//front
        x = i, y = j, z = p;
        return;
    case 1:	//left
        x = i, y = p, z = n - j - 1;
        return;
    case 2:	//back
        x = i, y = n - j - 1, z = n - p - 1;
        return;
    case 3:	//right
        x = i, y = n - p - 1, z = j;
        return;
    case 4:	//top
        x = p, y = j, z = n - i - 1;
        return;
    case 5:	//bottom
        x = n - p - 1, y = j, z = i;
        return;
    }
}

int solve()
{
    int x, y, z;

    REP(k, 6) REP(i, n) REP(j, n)
    if (view[k][i][j] == '.')	//�p�G�[�ݮɬ��ŤߡA�Npos�}�C�ХܪŤ�
        REP(p, n)
    {
        search(i, j, k, p, x, y, z);
        pos[x][y][z] = '.';
    }
    while (true)
    {
        bool flag = true;
        REP(k, 6) REP(i, n) REP(j, n)
        if (view[k][i][j] != '.')	//�p�G�[�ݮɬ��D�Ťߪ��I
            REP(p, n)
        {
            search(i, j, k, p, x, y, z);	//�ˬd���ӭ�

            if (pos[x][y][z] == '.') //�ˬd�٨S���ХܹL���A�p�G�O'.'�N�Хܬ��Ť�
                continue;	//�����U�����{���A�~��U�@���j��

            if (pos[x][y][z] == '#') //�p�G�S���Q�ХܹL
                pos[x][y][z] = view[k][i][j];

            if(pos[x][y][z] == view[k][i][j])	//�p�G�o�Ӧ�m�C��ۦP�A��ܦs�b�A���Υ���
                break;

            pos[x][y][z] = '.';
            flag = false;
        }
        if (flag==true)
            break;
    }

    int ans = 0;
    REP(x, n) REP(y, n) REP(z, n)	//�p��D�Ťߪ���n
    {
        if (pos[x][y][z] != '.') //�p�G���O�ŤߴN��ans+1
            ans++;
    }
    return ans;
}

int main ()
{
    while (cin>>n && n!=0)
    {
        input();
        cout<<"Maximum weight: "<<solve()<<" gram(s)"<<endl;
    }
    return 0;
}
