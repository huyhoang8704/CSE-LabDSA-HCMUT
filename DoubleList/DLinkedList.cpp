#include <bits/stdc++.h>
#include <list>
using namespace std;

template <class T>
class DLinkedList
{
public:
    class Iterator; // forward declaration
    class Node;     // forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    DLinkedList() : head(NULL), tail(NULL), count(0){};
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &item);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }

public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

        Iterator begin()
        {
            return Iterator(this, true);
        }
        Iterator end()
        {
            return Iterator(this, false);
        }

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();

        // Prefix ++ overload
        Iterator &operator++();

        // Postfix ++ overload
        Iterator operator++(int);
    };
};

template <class T>
void DLinkedList<T>::add(const T &e)
{
    /* Insert an element into the end of the list. */

    Node *temp = new Node;
    temp->data = e;

    if (head == NULL || tail == NULL)
    {
        head = tail = temp;
        count++;
        return;
    }

    tail->next = temp;
    temp->previous = tail;
    tail = temp;
    count++;
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
    /* Insert an element into the list at given index. */
    if (index < 0 || index > count)
        return;

    Node *newNode = new Node(e);
    if (index == 0)
    {
        newNode->next = head;
        if (head)
        {
            head->previous = newNode;
            head = newNode;
        }
        else
        {
            head = tail = newNode;
        }
    }
    else if (index == count)
    {
        newNode->previous = tail;
        if (tail)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            head = tail = newNode;
        }
    }
    else
    {
        Node *ptr = head;
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
        }

        newNode->next = ptr->next;
        ptr->next->previous = newNode;
        newNode->previous = ptr;
        ptr->next = newNode;
    }
    count++;
}
template <class T>
int DLinkedList<T>::size()
{
    /* Return the length (size) of list */
    return count;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    T data = current->data;
    if (current->previous != nullptr)
    {
        current->previous->next = current->next;
    }
    else
    {
        // current is head
        head = current->next;
    }
    if (current->next != nullptr)
    {
        current->next->previous = current->previous;
    }
    else
    {
        // current is tail
        tail = current->previous;
    }
    count -= 1;
    return data;
}

template <class T>
bool DLinkedList<T>::removeItem(const T &item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node *current = head;
    int index = 0;
    while (current != nullptr)
    {
        if (current->data == item)
        {
            if (current->previous != nullptr)
            {
                current->previous->next = current->next;
            }
            else
            {
                // current is head
                head = current->next;
            }
            if (current->next != nullptr)
            {
                current->next->previous = current->previous;
            }
            else
            {
                // current is tail
                tail = current->previous;
            }
            count -= 1;
            return true;
        }
        current = current->next;
        index += 1;
    }
    return false;
}

template <class T>
void DLinkedList<T>::clear()
{
    /* Remove all elements in list */
    while (count > 0)
    {
        removeAt(0);
    }
}

template <class T>
T DLinkedList<T>::get(int index)
{
    /* Give the data of the element at given index in the list. */
    Node *current = head;
    while (index > 0)
    {
        current = current->next;
        index -= 1;
    }
    return current->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T &e)
{
    Node *current = head;
    while (index > 0)
    {
        current = current->next;
        index -= 1;
    }
    current->data = e;
}

template <class T>
bool DLinkedList<T>::empty()
{
    /* Check if the list is empty or not. */
    return count == 0;
}

template <class T>
int DLinkedList<T>::indexOf(const T &item)
{
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node *current = head;
    int index = 0;
    while (current != nullptr)
    {
        if (current->data == item)
            return index;
        index += 1;
        current = current->next;
    }
    return -1;
}

template <class T>
bool DLinkedList<T>::contains(const T &item)
{
    /* Check if item appears in the list */
    return (indexOf(item) != -1);
}

/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin)
{
    this->pList = pList;
    if (begin)
    {
        if (pList != NULL)
        {
            this->current = pList->head;
            index = 0;
        }
        else
        {
            this->current = nullptr;
            index = -1;
        }
    }
    else
    {
        this->current = nullptr;
        if (pList != NULL)
        {
            index = pList->size();
        }
        else
        {
            index = 0;
        }
    }
}

template <class T>
typename DLinkedList<T>::Iterator &DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
}

template <class T>
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (current == NULL)
    {
        throw std::out_of_range("Segmentation fault!");
    }
    else
    {
        current->data = e;
    }
}

template <class T>
T &DLinkedList<T>::Iterator::operator*()
{
    if (current == NULL)
    {

        throw std::out_of_range("Segmentation fault!");
    }
    else
    {
        return current->data;
    }
}

template <class T>
void DLinkedList<T>::Iterator::remove()
{
    /*
     * TODO: delete Node in pList which Node* current point to.
     *       After that, Node* current point to the node before the node just deleted.
     *       If we remove first node of pList, Node* current point to nullptr.
     *       Then we use operator ++, Node* current will point to the head of pList.
     */
    if (current == nullptr)
    {
        return;
    }

    Node *nodeToRemove = current;
    current = current->previous;

    if (current != nullptr)
    {
        current->next = nodeToRemove->next;
    }
    else
    {
        pList->head = nodeToRemove->next;
    }

    if (nodeToRemove->next != nullptr)
    {
        nodeToRemove->next->previous = current;
    }
    else
    {
        pList->tail = current;
    }

    delete nodeToRemove;
    pList->count--;

    if (index > 0)
    {
        index--;
    }
}

template <class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator)
{
    if (this->pList == iterator.pList && this->current == iterator.current && this->index == iterator.index)
        return false;
    return true;
}

template <class T>
typename DLinkedList<T>::Iterator &DLinkedList<T>::Iterator::operator++()
{
    if (current == nullptr)
    {
        index = 0;
        current = this->pList->head;
        return *this;
    }
    current = current->next;
    index += 1;
    return *this;
}

template <class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int)
{
    DLinkedList<T>::Iterator iterator = *this;
    ++*this;
    return iterator;
}

class DataLog
{
private:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }

    void printLog()
    {
        for (auto i = logList.begin(); i != logList.end(); i++)
        {
            if (i == currentState)
                cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

DataLog::DataLog()
{
    /*
     * TODO:  add the first state with 0
     */
    logList = list<int>();
    logList.push_back(0);
    currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
    /*
     * TODO:  add the first state with data
     */
    logList = list<int>();
    logList.push_back(data);
    currentState = logList.begin();
}

void DataLog::addCurrentState(int number)
{
    /*
     * TODO: Increase the value of current state by number
     */
    (*currentState) += number;
}

void DataLog::subtractCurrentState(int number)
{
    /*
     * TODO: Decrease the value of current state by number
     */
    (*currentState) -= number;
}

void DataLog::save()
{
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the
     *       currentState Iterator, we delete them all before creating a new state.
     */
    logList.erase(next(currentState, 1), logList.end());
    logList.push_back(*currentState);
    currentState++;
}

void DataLog::undo()
{
    /*
     * TODO: Switch to the previous state of the data
     *       If this is the oldest state in the log, nothing changes
     */
    if (currentState == logList.begin())
        return;
    currentState--;
}

void DataLog::redo()
{
    /*
     * TODO: Switch to the latter state of the data
     *       If this is the latest state in the log, nothing changes
     */
    if (next(currentState, 1) == logList.end())
        return;
    currentState++;
}

struct ListNode
{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode *r = nullptr) : val(x), left(l), right(r) {}
};

ListNode *reverse(ListNode *head, int l, int r)
{
    if (!head || !head->right || l == r)
        return head;

    ListNode *prev = nullptr;
    ListNode *current = nullptr;

    for (int i = 0; i < l; i += 1)
    {
        if (current == nullptr)
            current = head;
        else
        {
            prev = current;
            current = current->right;
        };
    }

    ListNode *start = current;
    for (int i = l; i < r; i += 1)
    {
        current = current->right;
    }
    ListNode *end = current;

    if (prev != nullptr)
    {
        prev->right = end;
    }
    else
    {
        // is head
        head = end;
    }
    if (end->right)
    {
        end->right->left = start;
    }
    prev = end->right;
    while (start != end)
    {
        ListNode *next = start->right;
        start->right = prev;
        start->left = next;
        prev = start;
        start = next;
    }
    start->right = prev;

    return head;
}