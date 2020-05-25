#include <iostream>
using namespace std;

int main()
{
    int in1,c=1,i,n,in2,cn1,re,cost[36];

    cin>>in1;//輸入測資組數
    while(c<=in1)
    {
        cout<<"Case "<<c<<":"<<endl;//輸出第幾組

        for(i=0; i<36; i++) //輸入花費
        {
            cin>>cost[i];
        }

        cin>>n;//輸入數字數量
        while(n--)
        {
            cin>>in2;//輸入數字

            int min=0,de[37]= {0}; //歸零

            for(i=2; i<=36; i++) //計算每個進位的價錢
            {
                cn1=in2;//原本的數字不能動所以用其他變數
                int sum=0;//歸零

                while(cn1>0)//利用短除法將十進位轉成任何進位
                {
                    re=cn1%i;//取得餘數就是該進位要轉的數字
                    sum=sum+cost[re];//計算價錢
                    cn1=cn1/i;
                }

                if(min==0||sum<=min)//紀錄最少的花費
                {
                    de[i]=sum;
                    min=sum;
                }
            }

            cout<<"Cheapest base(s) for number "<<in2<<":";//輸出

            for(i=2; i<=36; i++)
            {
                if(de[i]==min)//輸出花費最少的進位
                {
                    cout<<" "<<i;
                }
            }
            cout<<endl;
        }

        if(c<in1)//最後一組測資不用換行
        {
            cout<<endl;
        }
        c++;
    }
    return 0;
}
