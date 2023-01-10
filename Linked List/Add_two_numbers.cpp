Node *reverse(Node *t)
{
    Node *pre = NULL;
    Node *cur = t;

    while (cur)
    {
        Node *nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    Node *F = reverse(first);
    Node *S = reverse(second);
    int sum = 0;
    Node *temp = new Node(-1);
    Node *ans = temp;
    while (F || S)
    {
        sum = sum / 10;
        if (F)
        {
            sum += F->data;
            F = F->next;
        }
        if (S)
        {
            sum += S->data;
            S = S->next;
        }
        ans->next = new Node(sum % 10);
        ans = ans->next;
    }
    if (sum / 10 == 1)
    {
        ans->next = new Node(1);
        ans = ans->next;
    }
    return reverse(temp->next);
}