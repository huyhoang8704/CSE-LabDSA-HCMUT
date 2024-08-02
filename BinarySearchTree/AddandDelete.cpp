Node *add(Node *node, T value)
{
    if (node == nullptr)
    {
        return new Node(value);
    }
    if (value < node->value)
    {
        node->pLeft = add(node->pLeft, value);
    }
    else
    {
        node->pRight = add(node->pRight, value);
    }
    return node;
}

void add(T value)
{
    root = add(root, value);
}

Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->pLeft != nullptr)
        current = current->pLeft;
    return current;
}

Node *deleteNode(Node *node, T value)
{
    if (node == nullptr)
        return node;
    if (value < node->value)
        node->pLeft = deleteNode(node->pLeft, value);
    else if (value > node->value)
        node->pRight = deleteNode(node->pRight, value);
    else
    {
        if (node->pLeft == nullptr)
        {
            Node *temp = node->pRight;
            delete node;
            return temp;
        }
        else if (node->pRight == nullptr)
        {
            Node *temp = node->pLeft;
            delete node;
            return temp;
        }
        Node *temp = minValueNode(node->pRight);
        node->value = temp->value;
        node->pRight = deleteNode(node->pRight, temp->value);
    }
    return node;
}

void deleteNode(T value)
{
    root = deleteNode(root, value);
}