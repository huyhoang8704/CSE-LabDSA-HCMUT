// You must use the nodes in the original list and must not modify ListNode's val attribute.
// Hint: You should complete the function mergeLists first and validate it using our first testcase example

ListNode *mergeLists(ListNode *a, ListNode *b)
{
    ListNode *result = nullptr;
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;
    if (a->val <= b->val)
    {
        result = a;
        result->next = mergeLists(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeLists(a, b->next);
    }
    return result;
}

void splitList(ListNode *source, ListNode **front, ListNode **back)
{
    ListNode *ptr1;
    ListNode *ptr2;
    ptr2 = source;
    ptr1 = source->next;

    // ptr1 is incrmented twice and ptr2 is icremented once.
    while (ptr1 != NULL)
    {
        ptr1 = ptr1->next;
        if (ptr1 != NULL)
        {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
    }

    // ptr2 is at the midpoint.
    *front = source;
    *back = ptr2->next;
    ptr2->next = NULL;
}

// Sort and unsorted list given its head pointer
ListNode *mergeSortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // split list
    ListNode *ptr1;
    ListNode *ptr2;
    splitList(head, &ptr1, &ptr2);

    // recursively merge sort
    ptr1 = mergeSortList(ptr1);
    ptr2 = mergeSortList(ptr2);

    return mergeLists(ptr1, ptr2);
}