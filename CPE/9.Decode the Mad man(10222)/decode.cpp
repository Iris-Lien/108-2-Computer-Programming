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
        // ���p�O�ťթδ���N������X
        if (c == ' ')
            cout << c;
        else if (c == '\n')
            cout << endl;
        else
        {
            if(c>='A'&&c<='Z')
                c+=32;
            // �j�M��J�r��, ��X��e��Ӧr��
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
