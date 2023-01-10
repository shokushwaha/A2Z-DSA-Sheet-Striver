struct Node *reverseList(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct Node *temp = head->next;
    struct Node *t = reverseList(temp);
    temp->next = head;
    head->next = NULL;
    return t;
}

public:
Node *addOne(Node *head)
{

    head = reverseList(head);
    int carry = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        carry = temp->data + carry;
        temp->data = carry % 10;
        carry = carry / 10;

        temp = temp->next;
    }
    head = reverseList(head);
    if (carry != 0)
    {
        temp = new Node(carry);
        temp->next = head;
        head = temp;
    }
    return head;
}
