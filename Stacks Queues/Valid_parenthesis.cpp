bool ispar(string x)
{
    stack<char> s;

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{')
            s.push(x[i]);

        else
        {
            if (s.empty())
                return false;
            else if (x[i] == ')' && s.top() != '(')
                return false;
            else if (x[i] == ']' && s.top() != '[')
                return false;
            else if (x[i] == '}' && s.top() != '{')
                return false;
            else
                s.pop();
        }
    }

    if (s.size() != 0)
        return false;

    return true;
}