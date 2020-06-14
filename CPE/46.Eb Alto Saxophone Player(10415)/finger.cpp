#include <iostream>
using namespace std;
int table_cdefgab[7][10] =
{
    0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 0, 0, 1, 1, 1, 1,
    0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
    0, 1, 1, 1, 0, 0, 1, 1, 0, 0,
    0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
    0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
};

int table_CDEFGAB[7][10] =
{
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 0, 0, 1, 1, 1, 0,
    1, 1, 1, 1, 0, 0, 1, 1, 0, 0,
    1, 1, 1, 1, 0, 0, 1, 0, 0, 0,
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
};

int main()
{
    int  n, finger[10], *p, *last_p;
    char buf[202];
    cin>>n;
    getchar();
    while (n --)
    {
        gets(buf);
        for (int i = 0; i <= 9; ++ i)
        {
            finger[i] = 0;
        }
        for (int i = 0; buf[i]; ++ i)
        {
            if (buf[i] >= 'a' && buf[i] <= 'g')
            {
                p = table_cdefgab[buf[i]-'a'];
            }
            else
            {
                p = table_CDEFGAB[buf[i]-'A'];
            }
            for (int j = 0; j <= 9; ++ j)
            {
                if (p[j] == 1 && (i == 0 || last_p[j] == 0))
                {
                    finger[j] ++;
                }
            }
            last_p = p;
        }

        for (int i = 0; i < 9; ++ i)
        {
            cout<<finger[i]<<" ";
        }
        cout<<finger[9]<<endl;
    }
    return 0;
}
