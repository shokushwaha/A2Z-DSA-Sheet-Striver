void MyStack ::push(int x)
{
    StackNode *temp = new StackNode(x);
    temp->next = top;
    top = temp;
}

int MyStack ::pop()
{
    if (top == NULL)
    {

        return -1;
    }

    else
    {

        int c = top->data;

        top = top->next;

        return c;
    }