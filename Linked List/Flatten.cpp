Node *merge(Node *a, Node *b)
{
    Node *temp = new Node(-1);
    Node *curr = temp;

    while (a && b)
    {
        if (a->data < b->data)
        {
            curr->bottom = a;
            a = a->bottom;
            curr = curr->bottom;
        }
        else
        {
            curr->bottom = b;
            b = b->bottom;
            curr = curr->bottom;
        }
    }

    if (a)
        curr->bottom = a;
    if (b)
        curr->bottom = b;

    return temp->bottom;
}
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);

    root = merge(root, root->next);
    return root;
}
