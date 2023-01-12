void MyStack ::push(int x)
{
    arr[++top] = x;
}

int MyStack ::pop()
{
    if (top == -1)
        return top;

    int x = arr[top];
    top -= 1;
    return x;
}