bool findValue(Node *node, int value)
{
    if (node == nullptr)
    {
        return false;
    }

    if (node->value == value)
    {
        return true;
    }
    else if (value < node->value)
    {
        return findValue(node->pLeft, value);
    }
    else
    {
        return findValue(node->pRight, value);
    }
}

bool find(int i)
{
    return findValue(root, i);
}

T sumRange(Node *node, T l, T r)
{
    if (node == nullptr)
    {
        return 0;
    }

    if (node->value < l)
    {
        return sumRange(node->pRight, l, r);
    }
    else if (node->value > r)
    {
        return sumRange(node->pLeft, l, r);
    }
    else
    {
        return node->value + sumRange(node->pLeft, l, r) + sumRange(node->pRight, l, r);
    }
}

T sum(T l, T r)
{
    return sumRange(root, l, r);
}