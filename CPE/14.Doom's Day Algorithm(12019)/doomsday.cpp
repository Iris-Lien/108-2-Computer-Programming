#include <iostream>
using namespace std;

int main()
{
    int n, month, day, totle = 0;
    int years_day[12] =   //�x�s�C�몺�Ѽ�
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> n;
    for(int i = 0; i < n; i++) //���X������N���ƴX��
    {
        cin >> month >> day;  //��J����M���
        if(month == 1)  //�p�G�O�@��
        {
            totle = (day + 5) % 7;
        }
        else  //�@��H�~�����
        {
            for(int j = 0; j < (month-1); j++)
            {
                totle = totle + years_day[j];
            }
            totle = (totle + day + 5)%7;
        }

        switch(totle)  //�Ѿl�ƧP�w�{�b�P���X
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
