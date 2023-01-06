struct Node *reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    Node *curr, *prev = NULL;

    curr = head;

    while (curr)
    {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}