#include<iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int i, j;
        for (i = 1;; i++)
        {
            int y = 0;
            for (j = 2; j < n; j++)
                y = (y + i) % j;
            if (y == 0)
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}