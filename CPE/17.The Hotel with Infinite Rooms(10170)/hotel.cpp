#include <iostream>
using namespace std;

int main()
{
    long long int first_people, day, mins;
    //�Ĥ@��(first_people)�H�Ȧ�ΤJ��A�Ѽƨ��(day)��
    while(cin >> first_people >> day)
    {
        while((day - first_people) >= 0)
        {
            day = day - first_people;
            if(day != 0)
            {
                first_people++;
            }
        }
        cout << first_people << endl;
    }
    return 0;
}
/*
1. first_people = 1, day = 6
(1�H)1
(2�H)2 3
(3�H)4 5 6
6-1>0
6-1-2>0
6-1-2-3=0
output : 3

2. first_people = 3, day = 10
(3�H)1 2 3
(4�H)4 5 6 7
(5�H)8 9 10
10-3>0
10-3-4>0
10-3-4-5<0
output : 5

3. first_people = 3, day = 14
(3�H)1  2  3
(4�H)4  5  6  7
(5�H)8  9  10 11 12
(6�H)13 14
output : 6
*/
