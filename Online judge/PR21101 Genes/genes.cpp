#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
struct E
{
    int gene=-1;    //將gene初始話為-1
    string child;
};
map<string, E> R;
map<string, vector<string> > g;
int dfs(string name)
{
    if(g[name].size() == 0) //如果輸入字串長為0就回傳
        return R[name].gene;
    //cout << name << "---------"<< endl;
    E &val = R[name];
    if(val.gene < 0)    //如果沒有被定義基因
    {
        int g1 = dfs(g[name][0]);
        int g2 = dfs(g[name][1]);
        if(g1 >= 0 && g2 >= 0)
        {
            if((g1 > 0 && g2 > 0) || (g1 == 1 || g2 == 1))
            {
                if(g1 == 1 && g2 == 1)  //如果g1和g2皆為顯性
                    val.gene = 1;
                else if(g1 == 1 && g2 == 2)     //如果g1為顯性且g2為隱性
                    val.gene = 1;
                else if(g1 == 2 && g2 == 1)     //如果g1為隱性且g2為顯性
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
        R.clear();  //清空R中的資料
        g.clear();  //清空g中的資料
        E foo;
        while(n--)
        {
            cin >> s1 >> s2;
            if(s2 == "dominant")    //如果基因為顯性就標示1
                R[s1].gene = 1;
            else if(s2 == "recessive")  //如果基因為隱性就標示2
                R[s1].gene = 2;
            else if(s2 == "non-existent")   //如果基因不存在就標示0
                R[s1].gene = 0;
            else
            {
                R[s1].child = s2;   //以上條件都不合就讓s2為child
                g[s2].push_back(s1);    //新增元素至vector_g的尾端
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
