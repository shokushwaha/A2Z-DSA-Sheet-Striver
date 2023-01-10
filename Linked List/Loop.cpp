bool detectLoop(Node *head)
{

    Node *slow = head;
    Node *fast = head->next;

    while (slow)
    {
        if (!fast || !fast->next)
            return false;

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}