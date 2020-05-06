#include <iostream>
#include <string>
using namespace std;

const char word[] = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
                    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\',
                    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
                    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};

int main()
{
    char c;
    while (cin.get(c))
    {
        // 假如是空白或換行就直接輸出
        if (c == ' ')
            cout << c;
        else if (c == '\n')
            cout << endl;
        else
        {
            if(c>='A'&&c<='Z')
                c+=32;
            // 搜尋輸入字元, 輸出其前兩個字元
            for (int i = 0; i < 47; i++)
            {
                if (word[i] == c)
                {
                    cout << word[i - 2];
                    break;
                }
            }
        }
    }
    return 0;
}
