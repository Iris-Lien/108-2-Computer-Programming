#include <iostream>
#include<string>
using namespace std;

int main()
{
    string input;
    while (cin >> input && input != "0")
    {
        int degree = 0,Count = 0;
        for (int i=0;i<input.length();i++)
            Count += ( input[i] - '0' );
        while ( 1 )
        {
            if ( Count % 9 )
                break;
            else if ( Count == 9 )
            {
                degree ++;
                break;
            }
            int temp = 0;
            while ( Count )
            {
                temp += ( Count % 10 );
                Count /= 10;
            }
            Count = temp;
            degree ++;
        }
        if ( degree )
            printf("%s is a multiple of 9 and has 9-degree %d.\n",input.c_str(),degree);
        else
            cout << input << " is not a multiple of 9.\n";
    }
    return 0;
}
