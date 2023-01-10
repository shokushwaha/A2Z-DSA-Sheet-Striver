Node *deleteMid(Node *head)
{
    int cnt = 0;

    Node *temp = head;

    while (temp)
    {
        temp = temp->next;
        cnt++;
    }

    int i = 0;
    temp = head;
    while (i < cnt / 2 - 1)
    {
        i++;
        temp = temp->next;
    }

    temp->next = temp->next->next;

    return head;
}