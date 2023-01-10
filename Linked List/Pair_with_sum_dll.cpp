vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> ans;

    Node *start = head;

    Node *end = head;

    while (end->next)
        end = end->next;

    while (start != end && start->data < end->data)
    {
        int sum = start->data + end->data;

        if (sum == target)
        {
            pair<int, int> p = make_pair(start->data, end->data);
            ans.push_back(p);
            start = start->next;
            end = end->prev;
        }

        else if (sum < target)
            start = start->next;

        else
            end = end->prev;
    }

    return ans;
}