ListNode *_reverseKGroup(ListNode *head, int size, int k)
{
    if (head == nullptr || size < k)
        return head;
    ListNode *prev = nullptr, *cur = head, *next = nullptr;
    int count = 0;
    while (cur != nullptr && count < k)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }
    head->next = _reverseKGroup(next, size - k, k);
    return prev;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    int size = 0;
    ListNode *temp = head, *root;
    while (temp != nullptr)
    {
        temp = temp->next;
        size++;
    }
    return _reverseKGroup(head, size, k);
}