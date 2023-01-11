void removeDuplicates(struct Node **head)
{
    Node *slow = *head;
    Node *fast = *head;

    while (fast)
    {
        if (fast->data != slow->data)
        {
            slow->next = fast;
            fast->prev = slow;
            slow = fast;
        }
        fast = fast->next;
    }
    slow->next = NULL;
}