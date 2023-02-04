bool ispar(string x)
{
    stack<char> s;

    for (int i = 0; i < x.size(); i++)
    {
        char y = x[i];

        if (y == '(' || y == '[' || y == '{')
            s.push(y);
        else if (s.empty())
            return false;
        else if (y == ')' && s.top() != '(')
            return false;
        else if (y == ']' && s.top() != '[')
            return false;
        else if (y == '}' && s.top() != '{')
            return false;
        else
            s.pop();
    }
    if (!s.empty())
        return false;

    return true;
}