pair<int, int> diameterFast(Node *root)
{
    // making a pair to store the diameter in first field and height in second field
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int diameter(Node *root)
{

    pair<int, int> ans = diameterFase(root);
    int dia = ans.first;
    int height = ans.second;

    return dia;
}