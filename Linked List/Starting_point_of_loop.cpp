int start(Node *root)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            break;
        }
    }

    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}