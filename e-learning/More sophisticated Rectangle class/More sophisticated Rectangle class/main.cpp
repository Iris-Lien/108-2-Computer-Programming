#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Rectangle
{
public:
    float line[3];
    void setCoordinate(int c[4][2])
    {
        for (int i = 0;i < 4;i++)
            for (int j = 0;j < 2;j++)
                coord[i][j] = c[i][j];
    }
    int getLength()
    {
        int i, j;

        for (i = 0;i < 3;i++)
            line[i] = sqrt((coord[0][1] - coord[i + 1][1]) * (coord[0][1] - coord[i + 1][1])
                + (coord[0][0] - coord[i + 1][0]) * (coord[0][0] - coord[i + 1][0]));

        sort(line, line + 3);

        return line[1];
    }//The length is the larger of the two dimensions
    int getWidth()
    {
        //getLength();
        return line[0];
    }
    int getPerimeter()
    {
        return 2 * (getLength() + getWidth());
    }
    int getArea()
    {
        return getLength() * getWidth();
    }
private:
    int coord[4][2];
};

int main()
{
    Rectangle test;
    int i, j;
    int ctest[4][2];

    for (i = 0;i < 4;i++)
        for (j = 0;j < 2;j++)
            cin >> ctest[i][j];

    test.setCoordinate(ctest);
    cout << test.getLength() << endl;
    cout << test.getWidth() << endl;
    cout << test.getPerimeter() << endl;
    cout << test.getArea() << endl;


    return 0;
}