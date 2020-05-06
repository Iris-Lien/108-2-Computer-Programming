class member
{
public:
    member(int r)
    {
        rewards = r;
    }
    int getCoupon()
    {
        return 1;
    }
    float feedbackRate()
    {
        return rewards*1.2;
    }
protected:
    int rewards;
};

class gold_member : public member
{
public:
    int getCoupon()
    {
        return 2;
    }
    float feedbackRate()
    {
        return member::feedbackRate()*1.2/rewards;
    }
};

int main()
{

}
