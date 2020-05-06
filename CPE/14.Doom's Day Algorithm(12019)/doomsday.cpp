#include <iostream>
using namespace std;

int main()
{
    int n, month, day, totle = 0;
    int years_day[12] =   //儲存每月的天數
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> n;
    for(int i = 0; i < n; i++) //有幾筆測資就重複幾次
    {
        cin >> month >> day;  //輸入月份和日期
        if(month == 1)  //如果是一月
        {
            totle = (day + 5) % 7;
        }
        else  //一月以外的月份
        {
            for(int j = 0; j < (month-1); j++)
            {
                totle = totle + years_day[j];
            }
            totle = (totle + day + 5)%7;
        }

        switch(totle)  //由餘數判定現在星期幾
        {
        case 0:
            cout << "Sunday" << endl;
            break;
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
        }
        totle = 0;
    }
    return 0;
}
