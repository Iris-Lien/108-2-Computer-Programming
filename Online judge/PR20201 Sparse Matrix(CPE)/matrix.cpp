#include<iostream>

using namespace std;
int main()
{
    int row,column,data;
    int i,j;

    cin>>row>>column>>data;

    int array[row][column];
    for(i = 0 ; i < row ; i++)
    {
        for(j = 0 ; j < column ; j++)
        {
            array[i][j] = 0;
        }
    }
    for(i=0;i<data;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        array[a][b]=c;
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
