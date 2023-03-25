void solve(Node *&head1, Node *&head2)
{
    Node *prev = head1;
    Node *curr = head1->next;
    Node *temp = head2;
    Node *temp2 = NULL;
    while (curr && temp)
    {
        int val = temp->data;

        if (val >= prev->data && val <= curr->data)
        {
            prev->next = temp;
            temp2 = temp->next;
            prev = temp;
            temp->next = curr;
            temp = temp2;
        }

        else
        {
            curr = curr->next;
        }
    }
}
Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    if (head1->data <= head2->data)
    {
        solve(head1, head2);
        return head1;
    }
    else
    {
        solve(head2, head1);
        return head2;
    }
}