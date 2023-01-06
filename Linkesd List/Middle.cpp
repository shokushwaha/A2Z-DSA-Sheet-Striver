int getMiddle(Node *head)
{
    // Your code here
    Node *slow = head, *fast = head;

    while (fast and fast->next)
    {

        fast = fast->next->next;

        slow = slow->next;
    }

    return slow->data;
}