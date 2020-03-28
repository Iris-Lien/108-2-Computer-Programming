#include<iostream>

using namespace std;

class Rectangle
{
public:
    void setLengthandWidth( int length, int width)
    {
        RectangleLength=length;
        RectangleWidth=width;
    }
    int getPerimeter()
    {
        return 2*(RectangleLength+RectangleWidth);
    }
    int getArea()
    {
        return RectangleLength*RectangleWidth;
    }
private:
    int RectangleLength;
    int RectangleWidth;
};

int main()
{
    int len,wid;
    cin>>len>>wid;
    Rectangle rec;
    rec.setLengthandWidth(len,wid);
    cout<<rec.getPerimeter()<<endl;
    cout<<rec.getArea()<<endl;
    return 0;
}
