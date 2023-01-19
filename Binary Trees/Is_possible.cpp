bool isPossible(int a, int b)
{
    if ((a == 2 || b == 2) && (a != b))
    {
        return true;
    }
    else
    {
        return false;
    }
}