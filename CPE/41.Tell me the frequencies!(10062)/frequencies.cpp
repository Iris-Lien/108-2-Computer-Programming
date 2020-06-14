#include<iostream>
#include<string>
using namespace std;

void solve(string str)
{
    int count[130] = {0}; //計數每個ASCII 各有多少個
    int maxCount = 0; //計數總共有幾個ASCII

    for(int i = 0 ; i < str.length() ; i++)
    {
        count[str[i]]++;
        maxCount++;
    }

    //因為要照大小輸出 從1~maxCount逐一比對
    for(int j = 1 ; j <= maxCount ; j++)
    {
        //若ASCII CODE一樣則從大的開始輸出
        for(int i = 128  ; i >= 32 ; i--)
        {
            if(count[i] == j)
                cout << i << " " << j << endl;
        }
    }

}
int main()
{
    string str;
    bool flag = false;
    while(getline(cin, str))
    {
        if(flag)
            cout << endl;

        solve(str);
        flag = true;
    }
    return 0;
}
