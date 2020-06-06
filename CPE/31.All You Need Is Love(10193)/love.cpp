#include <iostream>
#include <cstdio>
using namespace std;

int binaryStringToInt(string s)
{
    int num = 0;
    for(int i = 0 ; i < s.length() ; ++i)
    {
        num <<= 1;
        num += s[i] - '0';
    }
    return num;
}

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return a + b;
    while((a %= b) != 0 && (b %= a) != 0);
    return a + b;
}

int main()
{
    int N;
    while(scanf("%d", &N) != EOF)
    {
        for(int caseNumber = 1 ; caseNumber <= N ; ++caseNumber)
        {
            string s1, s2;
            cin >> s1 >> s2;

            int num1 = binaryStringToInt(s1), num2 = binaryStringToInt(s2);
            printf("Pair #%d: ", caseNumber);
            if(gcd(num1, num2) != 1)
            {
                printf("All you need is love!\n");
            }
            else
            {
                printf("Love is not all you need!\n");
            }
        }
    }
    return 0;
}
