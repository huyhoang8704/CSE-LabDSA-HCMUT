#include<iostream>
#include <cassert>

using namespace std;

template <class T>
class SLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    SLinkedList() : head(NULL), tail(NULL), count(0){};
    ~SLinkedList(){}
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
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
        friend class SLinkedList<T>;
    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator(){}
        Iterator(SLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
        void remove();
    };
};

template <class T>
void SLinkedList<T>::add(const T& e) {
    if(count == 0){
        head = tail = new Node(e);
        
    }
    else{
        Node* tmp = new Node(e);
        tail->next = tmp;
        tail = tmp;
    }
    count++;
    
}
//! hiện thực các hàm như ở câu 1
template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    if(index < 0 || index > count) return;
    else if(count == 0 || index == count) add(e);
    else if(index == 0){
        Node* tmp = new Node(e);
        tmp->next = head;
        head = tmp;
        count ++;
    }
    else{
        index --;
        Node* tmp = head;
        Node* New = new Node(e);
        while(index){ 
            tmp = tmp->next;
            index--;
        }
        New->next = tmp->next;
        tmp->next = New;
        count ++;
    } 
    
}

template<class T>
int SLinkedList<T>::size() {
   return count;
}
template<class T>
T SLinkedList<T>::get(int index) {
//! ném ra ngoại lệ
     if(index < 0 || index >= count) throw out_of_range("");
    Node* tmp = head;
    while(index){
        index --;
        tmp = tmp->next;
    }
    return tmp->data;
    
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
//! ném ra ngoại lệ 
    if(index < 0 || index >= count) throw out_of_range("");
    Node* tmp = head;
    while(index){
        index --;
        tmp = tmp->next;
    }
    tmp->data = e;
}

template<class T>
bool SLinkedList<T>::empty() {
    return count == 0;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    //* Return the first index wheter item appears in list, otherwise return -1 *//
    int i = 0;
    Node* tmp = head;
    while(tmp){
        if(tmp->data == item) return i;
        i ++;
        tmp = tmp->next;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    Node* tmp = head;
//! duyệt vòng while
    while(tmp){
        if(tmp->data == item) return true;
        tmp = tmp->next;
    }
    return false;
    
}
//! hiện thực hàm toString 
template<class T>
string SLinkedList<T>::toString() {
    string s = "[";
    Node* current = head;
    
    while (current) {
        s+= to_string(current->data);
       
        if (current->next) {
            s+= ",";
        }
        current = current->next;
    }
   s+= "]";
    return s;
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    T result;
//! nếu đúng thì chương trình chạy sai thì dừng chương trình 
    if(index < 0 || index > count || count == 0) throw out_of_range("");
//! nếu chỉ có 1 phần tử đầu tiên thì reset head = tail = nullptr
    else if(count == 1){
        result = head->data;
        delete head;
        head =tail = nullptr;
    }
//! nếu xóa ở vị trí 0 thì 
    else if(index == 0){
//! lưu data của node đầu tiên lại
        result = head->data;
        Node* tmp = head;
        head = head->next;
//! xóa vùng nhớ
        delete tmp;
    }
    else{
//! giảm index xuống 1 đơn vị
        index --;
        Node* tmp = head;
//! dùng vòng lặp đến vị trí cần tìm
        while(index){
            tmp = tmp->next;
            index --;
        }
        if(tmp->next->next){
            Node* d = tmp->next;
            tmp->next = tmp->next->next;
            result = d->data;
            delete d;
        }
        else{
//! nếu không thỏa if thì phải lưu tail lại vì phần tử đang xóa là phần tử ở vị trí cuối cùng
            tail = tmp;
            Node* d = tmp->next;
            tmp->next = nullptr;
            result = d->data;
            delete d;
        }
    }
    count --;
    return result;
}
//!  
template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
//! xóa node có giá trị bằng phần tử ở vị trí đầu tiên của danh sách nếu có phần tử thì xóa rồi trả về true không thì ngược lại
   int index = indexOf(item);
   if(index == -1 ) return false;
   removeAt(index);
   return true;
    
}
//! giải phóng các node 
template<class T>
void SLinkedList<T>::clear(){
    Node* tmp = head;
    while(tmp){
        tmp = tmp->next;
        delete head;
        head = tmp;
    }
    tail = head = NULL;
    count = 0;
}




template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList , bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
   //! hiện thực theo các điều kiện được note ở trên

   this->pList = pList;
   if(pList == NULL){}
   else if(begin){
        if(this->pList->size() == 0){this->current = NULL;index = -1;}
        else{ this->current = pList->head;index = 0;}
   }
   else{
        this->current = NULL;
        if(this->pList->size() == 0) index = this->pList->size();
        else index = pList->size();
   }
    
    
}
//! typename được sử dụng để thông báo cho trình biên dịch rằng SLinkedList<T>::Iterator là một tên kiểu
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
    // cout << this->index;
//! gán các giá trí của iterator
    this->pList = iterator.pList;
    this->current = iterator.current;
    this->index = iterator.index;
    return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
//! nếu hiện tại đang là Null thì ném ra ngoại lệ "Segmentation fault!""
   if(this->current == NULL) throw out_of_range("Segmentation fault!");
//! tìm vị trí đầu tiên của phần tử bằng hàm indexOf 
    int index = this->pList->indexOf(this->current->data);
//! nếu index  đang ở vị trí không
    if(index == 0){
        this->pList->removeAt(index);
        this->index = -1;
        current = NULL;
    }
    else{
        T e = this->pList->removeAt(index-1);
        this->index = index - 1;
        current->data = e;
        //current = this->pList->get(index - 1);
    }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if(current == NULL) throw out_of_range("Segmentation fault!");
    current->data = e;
}   

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
   if(current == NULL) throw out_of_range("Segmentation fault!");
   //cout << current->data;
   return current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns false if two iterators points the same node and index
    */
   return !(iterator.index == this->index || iterator.current == this->current);
}
//! Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if(current == NULL) throw out_of_range("Segmentation fault!");
    current = current->next;
    index++;
    return *this;
}
//! Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if(current == NULL) throw out_of_range("Segmentation fault!");
    Iterator temp = *this;
    current = current->next;
    index++;    
    return temp;
}
class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
//! Cho phép lớp Polynomial truy cập vào thành viên riêng tư của Term.
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
//! Toán tử so sánh hai thuật ngữ
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
//! Toán tử xuất để in thuật ngữ ra màn hình
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
//! Danh sách các thuật ngữ của đa thức, sử dụng lớp SLinkedList.
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};


void Polynomial::insertTerm(const Term& term) {
     if(term.exp < 0 ||  term.coeff == 0) return;
     SLinkedList<Term>::Iterator it;
     int i = 0;
    for (SLinkedList<Term>::Iterator it = this->terms->begin(); it != this->terms->end(); it++) {
        Term t = *it;
        if(t.exp == term.exp){
            t.coeff += term.coeff;
            if(t.coeff != 0) it.set(t);
            else it.remove();
            return;
        }
        else if(t.exp < term.exp){ // số mũ cần thêm vào lớn hơn list 
            break;
        }
        i++;
    }
    this->terms->add(i,term); // nếu không có số mũ đó thì tự thêm
}

void Polynomial::insertTerm(double coeff, int exp) {
    Term t(coeff,exp);
    insertTerm(t);  
}

int main(){
   
Polynomial *poly = new Polynomial();
poly->insertTerm(6.0, 2);
poly->insertTerm(4.0, 5);
poly->insertTerm(4.0, 3);
poly->insertTerm(6.0, 5);
poly->insertTerm(-1.0, 0);
poly->insertTerm(-6.0, 6);
poly->insertTerm(6.0, 6);
poly->print();

        /*[
        Term: (10 5)
        Term: (4 3)
        Term: (6 2)
        Term: (-1 0)
        ]*/

    int n = 5;
    int coeff[] = { 1, 2, 3, 4, 5 };
    int exp[] = { 1, 2, 3, 4, 5 };

    Polynomial p1;
    for (int i = 0; i < n; ++i)
        p1.insertTerm(coeff[i], exp[i]);

    p1.print();       
            /*[
        Term: (5 5)
        Term: (4 4)
        Term: (3 3)
        Term: (2 2)
        Term: (1 1)
        ]*/

}