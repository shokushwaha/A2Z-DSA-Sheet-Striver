void addNode(Node *head, int pos, int data)
{
    int i = 0;
    Node *temp = new Node(data);
    // head is empty
    if (head == NULL)
        return;

    Node *curr = head;
    while (i != pos)
    {
        i++;
        curr = curr->next;
    }
    // last position
    if (curr->next == NULL)
    {
        curr->next = temp;
        temp->prev = curr;
        temp->next = NULL;
    }

    // in between
    else
    {
        temp->next = curr->next;
        curr->next->prev = temp;
        temp->prev = curr;
        curr->next = temp;
    }
}