#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define REP(i,n) for (int i = 0; i < (n); i++)	//將REP定義為for迴圈

const int N = 15;

char view[N][N][N], pos[N][N][N];	//宣告觀看時的六面體陣列和一般六面體陣列
int n;

char getChar() //截取字元
{
    char ch;
    while (true)
    {
        ch = getchar();
        if ((ch >= 'A' && ch <= 'Z') || ch == '.')	//判斷是否為字母或空心
            return ch;
    }
}

void input()
{
    REP(i, n) REP(k, 6) REP(j, n) view[k][i][j] = getChar();	//將觀看時的顏色存入view陣列裡
    REP(x, n) REP(y, n) REP(z, n) pos[x][y][z] = '#';	//將pos陣列初始化為'#'
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
    if (view[k][i][j] == '.')	//如果觀看時為空心，將pos陣列標示空心
        REP(p, n)
    {
        search(i, j, k, p, x, y, z);
        pos[x][y][z] = '.';
    }
    while (true)
    {
        bool flag = true;
        REP(k, 6) REP(i, n) REP(j, n)
        if (view[k][i][j] != '.')	//如果觀看時為非空心的點
            REP(p, n)
        {
            search(i, j, k, p, x, y, z);	//檢查六個面

            if (pos[x][y][z] == '.') //檢查還沒有標示過的，如果是'.'就標示為空心
                continue;	//不做下面的程式，繼續下一次迴圈

            if (pos[x][y][z] == '#') //如果沒有被標示過
                pos[x][y][z] = view[k][i][j];

            if(pos[x][y][z] == view[k][i][j])	//如果這個位置顏色相同，表示存在，不用打空
                break;

            pos[x][y][z] = '.';
            flag = false;
        }
        if (flag==true)
            break;
    }

    int ans = 0;
    REP(x, n) REP(y, n) REP(z, n)	//計算非空心的體積
    {
        if (pos[x][y][z] != '.') //如果不是空心就讓ans+1
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
