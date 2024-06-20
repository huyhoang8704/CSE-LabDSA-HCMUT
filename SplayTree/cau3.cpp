// Write your helper functions here

Node* getMax(Node* p){
    while(p->pRight) p = p->pRight;
    return p;
}
Node* remove(int val){
    if(search(val)){
        if(!this->root->pLeft){
            Node* temp = this->root;
            this->root = this->root->pRight;
            if(this->root) this->root->pParent = NULL;
            return temp;
        }
        else{
            Node* rightTree = this->root->pRight;
            Node* leftTree = this->root->pLeft;
            Node* rs = this->root;
            this->root = leftTree;
            this->root->pParent = NULL;
            Node* p = getMax(this->root);
            splay(p);
            this->root->pRight = rightTree;
            if(rightTree) rightTree->pParent = this->root;
            return rs;
        }
    }
    return NULL;
}