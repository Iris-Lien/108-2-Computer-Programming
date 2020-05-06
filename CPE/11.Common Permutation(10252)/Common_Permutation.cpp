#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void countLetters(string s, int letterCount[])
{
    for( int i = 0 ; i < s.length() ; i++ )
        letterCount[(s[i]-'a')]++;
}

int main()
{
    string a, b;
    while( getline(cin, a) )
    {
        getline(cin, b);
        int aLetterCount[30] = {0}, bLetterCount[30] = {0};
        countLetters(a, aLetterCount);
        /*for(int j=0; j<30;j++)
            cout<<(char)(j+'a')<<aLetterCount[j]<<endl;*/

        countLetters(b, bLetterCount);
        /*for(int j=0; j<30;j++)
            cout<<(char)(j+'a')<<bLetterCount[j]<<endl;*/

        for( int i = 0 ; i < 26 ; i++ )
        {
            int commonCount = min(aLetterCount[i], bLetterCount[i]);
            for( int j = 0 ; j < commonCount ; j++ )
            {
                cout<<(char)(i+'a');
            }
        }
        cout<<endl;
    }
    return 0;
}
