#include <bits/stdc++.h>

using namespace std;

const int N = 5;

int main()
{
    map<char, int> m;
    m['r'] = 0, m['o'] = 1, m['y'] = 2, m['g'] = 3, m['b'] = 4;	//�N�^�����C��Х�01234�A���C������ۤ���������e��(PGSAN)
    string s;
    vector<string> v[N];	//�s�C�@�Ӧ^����񪺦^����
    while(cin >> s)
    {
        if(s[0] == '#') //Ū��#����
            break;
        else if(s[0] == 'e')
        {
            int end = v[0].size(), ans, maxc = 0;	//v[0].size()=�X�ӫ���
            for(int i = 0; i < end; i++)
            {
                int cnt = 0;
                for(int j = 0; j < end; j++)	//�q�Ĥ@�ӫ������^������Ǹ��L�����ۤ�A�M��ۦP���^����M�^�������X��
                {
                    for(int k = 0; k < N; k++)
                    {
                        if(v[k][i] == v[k][j])
                            cnt++;
                    }

                }
                if(cnt > maxc)	//�A�M��̤j�ȡA�N�H���ӫ��������
                {
                    maxc = cnt;
                    ans = i + 1;
                }
            }
            cout<<ans<<endl;
            for(int i = 0; i < N; i++)	//�M�Ÿ��
            {
                v[i].clear();
            }
        }
        else
        {
            for(int i = 0; i < 19; i += 4)	//�N��Ʀs�Jv��
            {
                v[m[s[i]]].push_back(s.substr(i, 3));		//��substr�r��I�����v
            }
        }
    }

    return 0;
}
