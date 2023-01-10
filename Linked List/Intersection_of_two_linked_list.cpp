Node *findIntersection(Node *head1, Node *head2)
{

    Node *temp = head2;
    set<int> s;
    while (temp)
    {
        s.insert(temp->data);
        temp = temp->next;
    }

    temp = head1;

    Node *dummy = new Node(-1);
    Node *ans = dummy;

    while (temp)
    {
        if (s.find(temp->data) != s.end())
        {
            ans->next = new Node(temp->data);
            ans = ans->next;
        }
        temp = temp->next;
    }

    return dummy->next;
}