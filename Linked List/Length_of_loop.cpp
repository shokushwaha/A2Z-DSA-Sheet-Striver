int length(Node *slow)
{
    Node *temp = slow;
    int cnt = 0;
    while (temp->next != slow)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt + 1;
}
int countNodesinLoop(struct Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return length(slow);
    }

    return 0;
}