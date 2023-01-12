void MyQueue ::push(int x)
{
    arr[rear] = x;
    rear++;
}

int MyQueue ::pop()
{
    if (rear == front)
        return -1;
    int x = arr[front];
    front++;
    return x;
}