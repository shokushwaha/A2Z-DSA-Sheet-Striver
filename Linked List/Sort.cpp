void sort(Node **head)
{
    vector<int> ans;

    Node *temp = *head;

    while (temp)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }

    sort(ans.begin(), ans.end());
    temp = *head;
    for (auto i : ans)
    {
        temp->data = i;
        temp = temp->next;
    }
}