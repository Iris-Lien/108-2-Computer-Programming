#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
struct E
{
    int gene=-1;    //�Ngene��l�ܬ�-1
    string child;
};
map<string, E> R;
map<string, vector<string> > g;
int dfs(string name)
{
    if(g[name].size() == 0) //�p�G��J�r�����0�N�^��
        return R[name].gene;
    //cout << name << "---------"<< endl;
    E &val = R[name];
    if(val.gene < 0)    //�p�G�S���Q�w�q��]
    {
        int g1 = dfs(g[name][0]);
        int g2 = dfs(g[name][1]);
        if(g1 >= 0 && g2 >= 0)
        {
            if((g1 > 0 && g2 > 0) || (g1 == 1 || g2 == 1))
            {
                if(g1 == 1 && g2 == 1)  //�p�Gg1�Mg2�Ҭ����
                    val.gene = 1;
                else if(g1 == 1 && g2 == 2)     //�p�Gg1����ʥBg2������
                    val.gene = 1;
                else if(g1 == 2 && g2 == 1)     //�p�Gg1�����ʥBg2�����
                    val.gene = 1;
                else
                    val.gene = 2;
            }
            else
            {
                val.gene = 0;
            }
        }
    }
    else
    {
        int g1 = dfs(g[name][0]);
        int g2 = dfs(g[name][0]);
        if(val.gene == 0)
        {
            if(g1 < 0 && g2 == 2)
            {
                R[g[name][0]].gene = 0;
                dfs(g[name][0]);
            }
            if(g2 < 0 && g1 == 2)
            {
                R[g[name][1]].gene = 0;
                dfs(g[name][1]);
            }
        }
        if(val.gene == 1)
        {
            if(g1 < 0 && g2 == 2)
            {
                R[g[name][0]].gene = 1;
                dfs(g[name][0]);
            }
            if(g2 < 0 && g1 == 2)
            {
                R[g[name][1]].gene = 1;
                dfs(g[name][1]);
            }
        }
        if(val.gene == 2)
        {
            if(g1 < 0 && g2 == 1)
            {
                R[g[name][0]].gene = 0;
                dfs(g[name][0]);
            }
            if(g1 < 0 && g2 == 2)
            {
                R[g[name][0]].gene = 2;
                dfs(g[name][0]);
            }
            if(g2 < 0 && g1 == 1)
            {
                R[g[name][1]].gene = 0;
                dfs(g[name][1]);
            }
            if(g2 < 0 && g1 == 2)
            {
                R[g[name][1]].gene = 2;
                dfs(g[name][1]);
            }
        }
    }
    return val.gene;
}
int main()
{
    int n;
    while(cin>>n)
    {
        string s1, s2;
        R.clear();  //�M��R�������
        g.clear();  //�M��g�������
        E foo;
        while(n--)
        {
            cin >> s1 >> s2;
            if(s2 == "dominant")    //�p�G��]����ʴN�Х�1
                R[s1].gene = 1;
            else if(s2 == "recessive")  //�p�G��]�����ʴN�Х�2
                R[s1].gene = 2;
            else if(s2 == "non-existent")   //�p�G��]���s�b�N�Х�0
                R[s1].gene = 0;
            else
            {
                R[s1].child = s2;   //�H�W���󳣤��X�N��s2��child
                g[s2].push_back(s1);    //�s�W������vector_g������
                if(R.find(s2) == R.end())
                    R[s2] = foo;
            }
        }
        for(map<string, E>::iterator it = R.begin(); it != R.end(); it++)
        {
            //cout << it->first <<" "<< it->second.child << "eee" << endl;
            if((it->second).child == "")
                dfs(it->first);
        }
        for(map<string, E>::iterator it = R.begin(); it != R.end(); it++)
        {
            cout << it->first << " ";
            int val = it->second.gene;
            if(val == 0)
                puts("non-existent");
            else if(val == 1)
                puts("dominant");
            else if(val == 2)
                puts("recessive");
            else
                while(1);
            //cout << it->first << " " << it->second.gene << endl;
        }
    }
    return 0;
}
