T getMinRec(Node *node)
{
    if (node == nullptr)
    {
        return T();
    }

    if (node->pLeft == nullptr)
    {
        return node->value;
    }

    return getMinRec(node->pLeft);
}

T getMin()
{
    return getMinRec(root);
}

T getMaxRec(Node *node)
{
    if (node == nullptr)
    {
        return T();
    }

    if (node->pRight == nullptr)
    {
        return node->value;
    }

    return getMaxRec(node->pRight);
}

T getMax()
{
    return getMaxRec(root);
}