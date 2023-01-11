Node *reverseDLL(Node *head)
{
    Node *curr = head, *prev = NULL, *nxt;

    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        curr->prev = nxt;

        prev = curr;
        curr = nxt;
    }
    return prev;
}
