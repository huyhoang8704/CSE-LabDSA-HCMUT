void push(T item) {
    // TODO: Push new element into the end of the queue
    this->list.add(item);
}

T pop() {
    // TODO: Remove an element in the head of the queue
    if (this->empty()) throw std::out_of_range("Empty Queue");
    return this->list.removeAt(0);
}

T top() {
    // TODO: Get value of the element in the head of the queue
    if (this->empty()) throw std::out_of_range("Empty Queue");
    return this->list.get(0);
}

bool empty() {
    // TODO: Determine if the queue is empty
    return this->list.empty();
}

int size() {
    // TODO: Get the size of the queue
    return this->list.size();
}

void clear() {
    // TODO: Clear all elements of the queue
    return this->list.clear();
}