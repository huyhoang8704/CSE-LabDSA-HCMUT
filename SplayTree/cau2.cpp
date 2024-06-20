// Write your helper functions here
bool search(int val){
    Node* p = this->root;
    Node* parent = nullptr;
    while(p){
        parent = p;
        if(p->val == val)  {
            splay(p);
            return true;
        }
        if(p->val < val) p = p->pRight;
        else p = p->pLeft;
    }
    if(parent) splay(parent);
    return  false;
}