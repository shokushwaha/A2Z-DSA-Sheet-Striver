Node *copyList(Node *head)
{
    Node *curr = head;
    Node *temp;

    while (curr)
    {
        temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = head;

    while (curr)
    {
        curr->next->arb = curr->arb ? curr->arb->next : curr->arb;
        curr = curr->next->next;
    }

    Node *original = head;
    Node *copy = head->next;
    temp = copy;
    while (original && copy)
    {
        original->next = original->next->next;
        copy->next = copy->next ? copy->next->next : copy->next;

        original = original->next;
        copy = copy->next;
    }
    return temp;
}
