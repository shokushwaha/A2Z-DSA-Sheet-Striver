void solve(string s, vector<string> &ans, string output, int index)
{
    if (index >= s.size())
    {
        if (output.size() >= 1)
            ans.push_back(output);

        return;
    }

    // including element at current index
    output.push_back(s[index]);
    solve(s, ans, output, index + 1);

    // excluding element at current index
    output.pop_back();
    solve(s, ans, output, index + 1);
}

vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(s, ans, output, index);
    sort(ans.begin(), ans.end());
    return ans;
}