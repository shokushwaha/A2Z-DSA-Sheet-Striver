ListNode *mergeKLists(vector<ListNode *> &lists)
{

    priority_queue<ListNode *, vector<ListNode *>, greater<ListNode *>> pq(cmp);

    for (auto list : lists)
    {
        if (list)
            pq.push(list);
    }

    ListNode dummy = new ListNode(-1);
    ListNode *curr = dummy;
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        curr->next = node;
        curr = curr->next;

        if (node->next)
            pq.push(node->next);
    }

    return dummy->next;
}
