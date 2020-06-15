#include <bits/stdc++.h>

using namespace std;

const int N = 5;

int main()
{
    map<char, int> m;
    m['r'] = 0, m['o'] = 1, m['y'] = 2, m['g'] = 3, m['b'] = 4;	//將回收桶顏色標示01234，讓顏色對應相比對應的內容物(PGSAN)
    string s;
    vector<string> v[N];	//存每一個回收桶放的回收物
    while(cin >> s)
    {
        if(s[0] == '#') //讀到#停止
            break;
        else if(s[0] == 'e')
        {
            int end = v[0].size(), ans, maxc = 0;	//v[0].size()=幾個城市
            for(int i = 0; i < end; i++)
            {
                int cnt = 0;
                for(int j = 0; j < end; j++)	//從第一個城市的回收桶為基準跟其他城市相比，尋找相同的回收桶和回收物有幾個
                {
                    for(int k = 0; k < N; k++)
                    {
                        if(v[k][i] == v[k][j])
                            cnt++;
                    }

                }
                if(cnt > maxc)	//再尋找最大值，就以那個城市為基準
                {
                    maxc = cnt;
                    ans = i + 1;
                }
            }
            cout<<ans<<endl;
            for(int i = 0; i < N; i++)	//清空資料
            {
                v[i].clear();
            }
        }
        else
        {
            for(int i = 0; i < 19; i += 4)	//將資料存入v裡
            {
                v[m[s[i]]].push_back(s.substr(i, 3));		//用substr字串截取放到v
            }
        }
    }

    return 0;
}
