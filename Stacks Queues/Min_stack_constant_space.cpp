stack<int> s;
int minEle;

int getMin()
{
    if (s.empty())
        return -1;
    return minEle;
}

int pop()
{

    if (s.empty())
        return -1;
    else
    {
        int x = s.top();
        s.pop();

        if (x >= minEle)
        {
            return x;
        }
        else
        {
            int mn = minEle;
            minEle = 2 * minEle - x;
            return mn;
        }
    }
}

void push(int x)
{
    if (s.empty())
    {
        minEle = x;
        s.push(x);
    }
    else
    {
        if (x >= minEle)
        {
            s.push(x);
        }
        else
        {
            int flag = 2 * x - minEle;
            minEle = x;
            s.push(flag);
        }
    }
}