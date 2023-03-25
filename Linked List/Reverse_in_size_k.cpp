// reverse all even if k>size of linked list
struct node *reverse(struct node *head, int k)
{
    struct node *curr = head, *prev = NULL, *nxt = NULL;

    int i = 0;
    while (curr != NULL && i < k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        i++;
    }
    if (nxt != NULL)
        head->next = reverse(nxt, k);
    return prev;
}

// only reverse if k<=size of linked list
ListNode *reverseKGroup(ListNode *head, int k)
{
    int len = 0;
    ListNode *temp = head;
    while (temp)
    {
        temp = temp->next;
        len++;
    }

    ListNode *curr = head, *prev = NULL, *nxt = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        count++;
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    len -= k;
    if (nxt != NULL && len >= k)
        head->next = reverseKGroup(nxt, k);
    else
        head->next = nxt;
    return prev;
}
