#include <bits/stdc++.h>

using namespace std;

const int N = 5;    //5個垃圾桶

int main()
{
    map<char, int> m;
    m['r'] = 0, m['o'] = 1, m['y'] = 2, m['g'] = 3, m['b'] = 4;
    string s;
    vector<string> v[N];
    while(cin >> s)
    {
        if(s[0] == '#')
        {
            break;
        }
        else if(s[0] == 'e')
        {
            int end = v[0].size(), ans, maxc = 0;
            for(int i = 0; i < end; i++)
            {
                int cnt = 0;
                for(int j = 0; j < end; j++)
                {
                    for(int k = 0; k < N; k++)
                    {
                        if(v[k][i] == v[k][j])
                        {
                            cnt++;
                        }
                    }

                }
                if(cnt > maxc)
                {
                    maxc = cnt;
                    ans = i + 1;    //因為陣列從0開始，加1才會為正確行數
                }
            }
            cout<<ans<<endl;
            for(int i = 0; i < N; i++)
            {
                v[i].clear();
            }
        }
        else
        {
            for(int i = 0; i < 19; i += 4)
            {
                v[m[s[i]]].push_back(s.substr(i, 3));   //將呼叫字串s索引i起的3個字元pupsh.back至v
            }
        }
    }

    return 0;
}
