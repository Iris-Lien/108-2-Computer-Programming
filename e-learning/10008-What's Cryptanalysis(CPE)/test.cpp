#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    int i,j;
    int sum[26]={0};
    char input[1000];
    int max=0;
    cin>>n;
    cin.getline(input, 1000);
    for(j=0;j<n;j++)
    {
        cin.getline(input, 1000);
        //cout<<input<<endl;
        for(i=0;input[i]!='\0';i++)
        {
            if(input[i]>='A'&&input[i]<='Z')
                sum[input[i]-'A']++;
            if(input[i]>='a'&&input[i]<='z')
            {
                input[i]-='a'-'A';
                sum[input[i]-'A']++;
            }
        }
    }
    for(i=0;i<26;i++)
    {
        if(sum[i]>max)
            max=sum[i];
    }
    for(j=max;j>0;j--)
    {
        for(i=0;i<26;i++)
        {
            if(sum[i]==j)
                cout<<(char)(i+'A')<<" "<<sum[i]<<endl;
        }
    }
    return 0;
}
