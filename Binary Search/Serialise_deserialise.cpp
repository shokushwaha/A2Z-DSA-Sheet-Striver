vector<int> serialize(Node *root)
{
    vector<int> ans;

    queue<Node *> q;

    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
            ans.push_back(-1);

        else
            ans.push_back(temp->data);

        if (temp)
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }

    return ans;
}

Node *deSerialize(vector<int> &A)
{

    Node *root = new Node(A[0]);

    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < A.size())
    {
        Node *temp = q.front();
        q.pop();

        if (A[i] == -1)
            temp->left = NULL;

        else
        {
            temp->left = new Node(A[i]);
            q.push(temp->left);
        }
        i++;

        if (A[i] == -1)
            temp->right = NULL;
        else
        {
            temp->right = new Node(A[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}