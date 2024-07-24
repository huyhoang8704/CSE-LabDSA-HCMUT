void push(T item) {
    // TODO: Push new element into the top of the stack
    this->list.add(0, item);
}

T pop() {
    // TODO: Remove an element on top of the stack
    if (this->list.empty()) throw std::out_of_range("Stack Underflow");
    return this->list.removeAt(0);
}

T top() {
    // TODO: Get value of the element on top of the stack
    if (this->list.empty()) throw std::out_of_range("Stack Underflow");
    return this->list.get(0);
}

bool empty() {
    // TODO: Determine if the stack is empty
    return this->list.empty();
}

int size() {
    // TODO: Get the size of the stack
    return this->list.size();
}

void clear() {
    // TODO: Clear all elements of the stack
    this->list.clear();
}