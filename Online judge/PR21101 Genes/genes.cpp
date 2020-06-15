#include <bits/stdc++.h>

using namespace std;

const int N = 3100;
int genes[N];

map<string, int> gene_map1 = {{"non-existent", -1}, {"recessive", 0}, {"dominant", 1}};
map<int, string> gene_map2 ={{-1, "non-existent"}, {0, "recessive"}, {1, "dominant"}};

map<string, int> m; //�s�H�W�M��]
vector<int> par[N];

int seq = 0;
int get(string& s)
{
    if(m.find(s) != m.end())
        return m[s];
    else
        return m[s] = seq++;    //�S�����N�[�J�s��map
}

int cal(int a, int b)
{
    if(a + b == 0)	//a&b��]��ܬҬ�����(0)�Ba&b��]��ܬ��@��(1)�@���s�b(-1)->�^������(0)
        return 0;
    else if(a + b > 0)	//a&b��]�䤤�@�Ӭ�����(1)->�^�Ƕ���(1)
        return 1;
    else	//�_�h�^�Ǥ��s�b(-1)
        return -1;
}

int dp(int k)
{
    if(genes[k] < 2)    //�p�G��]�w�Q�w�q
        return genes[k];
    else    //�_�h�M���������]�A���_��]�O�������
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
            par[get(b)].push_back(get(a));  //���������]�s���p��
    }

    for(auto &a : m)
        cout << a.first << " " << gene_map2[dp(a.second)] << endl;

    return 0;
}
