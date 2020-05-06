#include<iostream>

using namespace std;

int main()
{
    char input;
    int counter = 0;

    while(cin.get(input))
    {
        if(input == '"')
        {
            switch(counter % 2)
            {
            case 0:
                cout<<"*";
                break;
            case 1:
                cout<<"#";
                break;
            }
            counter++;
        }
        else if(input==' ')
            cout<<" ";
        else
            cout<<input;
    }


return 0;
}
