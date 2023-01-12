int priority(char c)
{
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}
string infixToPostfix(string s)
{
    int len = s.length();
    string res = "";
    stack<char> st;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            res += s[i];
        else if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(st.top()) >= priority(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}