Node *divide(int N, Node *head)
{

    Node *temp = head;
    Node *even = new Node(-1);
    Node *odd = new Node(-1);
    Node *evenAns = even;
    Node *oddAns = odd;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            evenAns->next = temp;
            evenAns = evenAns->next;
        }
        else
        {
            oddAns->next = temp;
            oddAns = oddAns->next;
        }
        temp = temp->next;
    }
    evenAns->next = odd->next;
    oddAns->next = NULL;
    head = even->next;
    delete even;
    delete odd;
    return head;
}