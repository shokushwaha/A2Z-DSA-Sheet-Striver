vector<int> calculateSpan(int price[], int n)
{
    // {element,index}
    stack<pair<int, int>> s;
    vector<int> index;

    for (int i = 0; i < n; i++)
    {

        if (s.size() == 0)
            index.push_back(-1);

        else if (s.top().first > price[i])
            index.push_back(s.top().second);

        else if (s.size() > 0 && s.top().first <= price[i])
        {
            while (s.size() && s.top().first <= price[i])
                s.pop();

            if (s.size() == 0)
                index.push_back(-1);
            else
                index.push_back(s.top().second);
        }
        s.push({price[i], i});
    }
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int x = i - index[i];
        ans.push_back(x);
    }
    return ans;
}