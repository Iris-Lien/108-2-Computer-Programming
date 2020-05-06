Point *Segment::getIntersection(Segment s)
{
    float m, n, c1, c2, x, y;
    m =(a.y-b.y)/(a.x-b.x);  //slope m�Ĥ@����{�����ײv
    c1=a.y-m*a.x;
    //y =m*x+c1;   //�Ĥ@����{��

    n =(s.getPointA().y-s.getPointB().y)/(s.getPointA().x-s.getPointB().x); //slope n�ĤG����{�����ײv
    c2=s.getPointA().y-n*s.getPointA().x;
    //y =n*x+c2; //�ĤG����{��


    Point *p=new Point();
    x=-(c1-c2)/(m-n);  //��������u�q�A���p�ߡA�D�X���Ix,y��
    y=m*x+c1;
    p->x=x;
    p->y=y;

    if(m!=n)       //��ײv���۵�->�꦳�@���I
    {
        if(a.x > b.x)        //��x���k����I�P�_���I�O�_�b�u�q�d��W
        {
            if((p->x > a.x) || (p->x < b.x))
            {
                return NULL;
            }
        }
        else if (a.x < b.x)
        {
            if((p->x > b.x) || (p->x < a.x))
            {
                return NULL;
            }
        }
        if (s.getPointA().x > s.getPointB().x)
        {
            if((p->x > s.getPointA().x) || (p->x < s.getPointB().x))
            {
                return NULL;
            }
        }
        else if (s.getPointA().x < s.getPointB().x)
        {
            if((p->x > s.getPointB().x) || (p->x < s.getPointA().x))
            {
                return NULL;
            }
        }
        return p;  //�H�W���󳣤����ߪ��ܦ^��p�I
    }

    if((a.x == b.x) && (a.y != b.y))  //�Ĥ@��ab�������u�q
    {
        if(a.y > b.y)
        {
            if(n*a.x+c2 >= a.y || n*a.x+c2 <= b.y)
                return NULL;
            else
                return p;
        }
        if(a.y < b.y)
        {
            if(n*a.x+c2 >= b.y || n*a.x+c2 <= a.y)
                return NULL;
            else
                return p;
        }
    }

    if((s.getPointA().x == s.getPointB().x) && (s.getPointA().y != s.getPointB().y)) //�ĤG��ab�������u�q
    {
        if (s.getPointA().y > s.getPointB().y)
        {
            if(m*s.getPointA().x+c1 >= s.getPointA().y || m*s.getPointA().x+c1 <= s.getPointB().y)
                return NULL;
            else
                return p;
        }
        if(s.getPointA().y < s.getPointB().y)
        {
            if(m*s.getPointA().x+c1 >= s.getPointB().y || m*s.getPointA().x+c1 <= s.getPointA().y)
                return NULL;
            else
                return p;
        }
    }

    else
        return NULL;
}
Path::Path(Point p[], int n)
{
    count = n - 1;
    for(int i=0 ; i<count ; i++)
    {
        Segment temp(p[i],p[i+1]);
        seg[i] = temp;
    }
}
float Path::getLength()
{
    float sum = 0;
    for(int i=0 ; i<count ; i++)
    {
        sum += seg[i].length();
    }
    return sum;
}
void Path::operator+=(const Point &p)
{
    Segment a(seg[count-1].getPointB(),p);
    for(int i=0 ; i<count-1 ; i++)
    {
        if(a.getIntersection(seg[i])!=NULL)
        {
            return;
        }
        seg[count] = a;
        count += 1;

    }
}
