stack<int> s;
stack<int> ss;
int getMin()
{
    if (ss.empty())
        return -1;
    return ss.top();
}

int pop()
{
    if (s.size() == 0)
        return -1;
    int ans = s.top();
    s.pop();

    if (ans == ss.top())
    {
        ss.pop();
        return ans;
    }
    return ans;
}

void push(int x)
{
    s.push(x);
    if (ss.size() == 0 || x <= ss.top())
        ss.push(x);
}