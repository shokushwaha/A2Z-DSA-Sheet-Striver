int findPos(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
            return i;
    }
    return -1;
}

Node *solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n)
{

    if (index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = post[index--];
    Node *res = new Node(element);
    int pos = findPos(in, element, n);

    res->right = solve(in, post, index, pos + 1, inorderEnd, n);
    res->left = solve(in, post, index, inorderStart, pos - 1, n);

    return res;
}

Node *buildTree(int in[], int post[], int n)
{
    int postOrderIndex = n - 1;
    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n);
    return ans;
}