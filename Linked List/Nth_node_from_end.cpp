int getNthFromLast(Node *head, int n)
{
    if (head == NULL)
        return -1;
    int cnt = 0;

    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }

    if (cnt < n)
        return -1;

    int i = 0;
    temp = head;
    while (i < cnt - n)
    {
        i++;
        temp = temp->next;
    }
    return temp->data;
}