// push element in q2
// then push all element of q1 into q1
// then swap q1 and q2
void QueueStack ::push(int x)
{
    q2.push(x);

    int count = q1.size();

    for (int i = 0; i < count; i++)
    {
        q2.push(q1.front());
        q1.pop();
    }

    count = q2.size();
    for (int i = 0; i < count; i++)
    {
        q1.push(q2.front());
        q2.pop();
    }
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    if (q1.empty())
        return -1;

    int x = q1.front();
    q1.pop();
    return x;
}
