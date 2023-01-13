Node *deleteNode(Node *head_ref, int x)
{
    struct Node *temp = head_ref;

    struct Node *prev;

    if (x == 1)

    {

        temp = temp->next;

        head_ref = temp;

        return head_ref;
    }

    for (int i = 0; i < x - 1; i++)

    {

        prev = temp;

        temp = temp->next;
    }

    prev->next = temp->next;

    return head_ref;
}