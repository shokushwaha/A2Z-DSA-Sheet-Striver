// by changing data
Node *segregate(Node *head)
{

    int c0 = 0, c1 = 0, c2 = 0;

    Node *temp = head;

    while (temp)
    {
        if (temp->data == 0)
            c0++;
        else if (temp->data == 1)
            c1++;
        else
            c2++;
        temp = temp->next;
    }

    temp = head;

    while (c0--)
    {
        temp->data = 0;
        temp = temp->next;
    }

    while (c1--)
    {
        temp->data = 1;
        temp = temp->next;
    }

    while (c2--)
    {
        temp->data = 2;
        temp = temp->next;
    }

    return head;
}

// by changing links
void insertAtTail(Node *&head, Node *curr)
{
    tail->next = curr;
    tail = curr;
}
Node *segregate(Node *head)
{
    Node *temp = head;
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    while (temp)
    {
        int val = temp->data;

        if (val == 0)
            insertAtTail(zeroTail, val);
        else if (val == 1)
            insertAtTail(oneTail, val);
        else if (val == 2)
            insertAtTail(twoTail, val);

        temp = temp->next;
    }

    if (oneHead->next != NULL)
        zeroTail->next = oneHead->next;
    else if (oneHead->next == NULL)
        zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}
