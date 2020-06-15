#include <bits/stdc++.h>

using namespace std;

const int N = 3100;
int genes[N];

map<string, int> gene_map1 = {{"non-existent", -1}, {"recessive", 0}, {"dominant", 1}};
map<int, string> gene_map2 ={{-1, "non-existent"}, {0, "recessive"}, {1, "dominant"}};

map<string, int> m; //存人名和基因
vector<int> par[N];

int seq = 0;
int get(string& s)
{
    if(m.find(s) != m.end())
        return m[s];
    else
        return m[s] = seq++;    //沒有找到就加入新的map
}

int cal(int a, int b)
{
    if(a + b == 0)	//a&b基因表示皆為隱性(0)、a&b基因表示為一陽(1)一不存在(-1)->回傳隱性(0)
        return 0;
    else if(a + b > 0)	//a&b基因其中一個為陽性(1)->回傳陽性(1)
        return 1;
    else	//否則回傳不存在(-1)
        return -1;
}

int dp(int k)
{
    if(genes[k] < 2)    //如果基因已被定義
        return genes[k];
    else    //否則尋找父母的基因，推斷基因是顯性隱性
        return genes[k] = cal(dp(par[k][0]), dp(par[k][1]));
}

int main()
{
    int n;
    string a, b;

    memset(genes, 3, sizeof(genes));

    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        if(gene_map1.find(b) != gene_map1.end())
            genes[get(a)] = gene_map1[b];
        else
            par[get(b)].push_back(get(a));  //把父母的基因存給小孩
    }

    for(auto &a : m)
        cout << a.first << " " << gene_map2[dp(a.second)] << endl;

    return 0;
}
