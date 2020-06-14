#include <iostream>

using namespace std;

const int MAX_NUM_CITIES = 27;

bool connectedAirline1[MAX_NUM_CITIES][MAX_NUM_CITIES];
bool connectedAirline2[MAX_NUM_CITIES][MAX_NUM_CITIES];

void ReadIn(bool connectedAirline[MAX_NUM_CITIES][MAX_NUM_CITIES])
{
    int N;
    cin >> N;

    while (N--)
    {
        char from, to;
        cin >> from >> to;

        connectedAirline[from - 'A'][to - 'A'] = true;  //�N����F�������Х�true
        connectedAirline[to - 'A'][from - 'A'] = true;
    }
}

void RunFloydWarshallOnBoth()
{
    for (int k = 0; k < MAX_NUM_CITIES; ++k)
    {
        for (int i = 0; i < MAX_NUM_CITIES; ++i)
        {
            for (int j = 0; j < MAX_NUM_CITIES; ++j)
            {
                connectedAirline1[i][j] |= (connectedAirline1[i][k] && connectedAirline1[k][j]);
                connectedAirline2[i][j] |= (connectedAirline2[i][k] && connectedAirline2[k][j]);
            }
        }
    }

}

int main()
{
    int T;

    cin >> T;

    for (int t = 0; t < T; ++t)
    {

        for (int i = 0; i < MAX_NUM_CITIES; ++i)    //�N�}�C��l�Ƭ�false
        {
            for (int j = 0; j < MAX_NUM_CITIES; ++j)
            {
                connectedAirline1[i][j] = connectedAirline2[i][j] = false;
            }
        }

        ReadIn(connectedAirline1);
        ReadIn(connectedAirline2);

        RunFloydWarshallOnBoth();

        bool equivalent = true;

        for (int i = 0; i < MAX_NUM_CITIES; ++i)    //�ˬd��a��Ť��q�i��F�M���i��F�����O�_�Ҭ��ۦP
            for (int j = 0; j < MAX_NUM_CITIES; ++j)
                equivalent &= (connectedAirline1[i][j] == connectedAirline2[i][j]);

        cout << (equivalent ? "YES" : "NO") << endl;    //�p�G�ۦP���ܿ�XYES�A�Ϥ���NO
        cout << endl;
    }
}
