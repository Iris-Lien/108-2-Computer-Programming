#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
    char input[3000], *temp;
    int j, x, index, ex = 1;
    int a[3000];
    while(cin>>x)
    {
        ex = 1;
        cin.getline(input, 3000);
        cin.getline(input, 3000);
        index = 0;
        temp = strtok(input, " ");
        while(temp != NULL)
        {
            //cout<<temp;
            a[index] = atoi(temp);
            index ++;
            temp = strtok(NULL, " ");
        }
        int ans = 0;
        for(j = 0; j < index - 2; j ++)
            ex = ex * x;
        for(j = 0; j < index; j ++, ex /= x)
        {
            ans += a[j] * (index - 1 - j) * ex;
        }
        cout<<ans<<endl;
    }
}
