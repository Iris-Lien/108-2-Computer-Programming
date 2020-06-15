#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int part1=0, part2=0, part3=0;
    string morse_table[500], dic[100], dicmorse[100], morse, ans[100], trmi="*";
    for(int i=0 ; cin>>morse_table[i]; i++)
    {
        part1=i;
        if(morse_table[i]==trmi)
            break;
    }
    for(int j=0; cin>>dic[j] ; j++)
    {
        part2=j;
        if(dic[j]==trmi)
            break;
        for(int x=0; x<dic[j].length(); x++)
        {
            for(int y=0; y<part1; y+=2)
            {
                if(dic[j][x]==morse_table[y][0])
                    dicmorse[j] += morse_table[y+1];
            }
        }
    }
    for (size_t i = 0 ; cin>>morse; i++)
    {
        if(morse==trmi)
            break;
        int same=0, same_ps;
        for(int p=0; p<part2; p++)
        {
            if(dicmorse[p]==morse)
            {
                same++;
                if(same==1)
                    same_ps=p;
            }
        }
        if(same)
        {
            ans[i]=dic[same_ps];
            if(same!=1)
                ans[i]+="!";
        }
        else
        {
            int big=0;
            for(int p=0; p<part2; p++)
            {
                int temp=0;
                for(int x=0; x<dicmorse[p].size(); x++)
                {
                    if(morse[x]==dicmorse[p][x])
                        temp++;
                    else
                        break;
                }
                if(big<temp)
                {
                    big = temp;
                    same_ps = p;
                }
            }
            ans[i]=dic[same_ps]+"?";
        }
        part3=i;
    }
    for(int i=0; i<=part3; i++)
        cout<<ans[i]<<endl;
}
