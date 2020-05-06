#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string input;
    while (cin >> input)
    {
        int sum = 0;
        int len = input.length();
        if (input == "0")
            break;
        for (int i = 0; i < len; i++)
        {
            if (i % 2 == 0)
                sum += (int)(input[i] - '0');
            else
                sum -= (int)(input[i] - '0');
        }
        sum = abs(sum);
        if (sum % 11 == 0)
            cout << input << " is a multiple of 11." << endl;
        else
            cout << input << " is not a multiple of 11." << endl;
    }
    return 0;
}
