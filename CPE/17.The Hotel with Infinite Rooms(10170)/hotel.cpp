#include <iostream>
using namespace std;

int main()
{
    long long int first_people, day, mins;
    //第一天(first_people)人旅行團入住，天數到第(day)天
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
(1人)1
(2人)2 3
(3人)4 5 6
6-1>0
6-1-2>0
6-1-2-3=0
output : 3

2. first_people = 3, day = 10
(3人)1 2 3
(4人)4 5 6 7
(5人)8 9 10
10-3>0
10-3-4>0
10-3-4-5<0
output : 5

3. first_people = 3, day = 14
(3人)1  2  3
(4人)4  5  6  7
(5人)8  9  10 11 12
(6人)13 14
output : 6
*/
