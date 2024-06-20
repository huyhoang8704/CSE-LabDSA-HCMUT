// write your helper functions here
void rotateLeft(Node* x){
    Node* y = x->pRight;
    x->pRight = y->pLeft;
    y->pLeft = x;
    y->pParent = x->pParent;
    x->pParent = y;
    if(x->pRight) 
        x->pRight->pParent = x;
    if(y->pParent) {
        if(x == y->pParent->pLeft) y->pParent->pLeft =y;
        else y->pParent->pRight = y;
    }
    else this->root = y;
}
void rotateRight(Node* x){
    Node* y = x->pLeft;
    x->pLeft = y->pRight;
    y->pRight = x;
    y->pParent = x->pParent;
    x->pParent = y;
    if(x->pLeft) 
        x->pLeft->pParent = x;
    if(y->pParent) {
        if(x == y->pParent->pLeft) y->pParent->pLeft =y;
        else y->pParent->pRight = y;
    }
    else this->root = y;
}
void splay(Node* x) {
    while(x->pParent){
        if(x->pParent->pParent == NULL){
            if(x == x->pParent->pLeft) 
                // zig rotation
                rotateRight(x->pParent);
            else
                // zag rotation
                rotateLeft(x->pParent);
        }
        else if(x == x->pParent->pLeft && x->pParent == x->pParent->pParent->pLeft){
                // zig-zig rotation
                rotateRight(x->pParent->pParent);
                rotateRight(x->pParent);
        }
        else if(x == x->pParent->pRight && x ->pParent == x->pParent->pParent->pRight){
                //zag-zag rotation
                rotateLeft(x->pParent->pParent);
                rotateLeft(x->pParent);
        }
        else if(x == x->pParent->pRight &&x->pParent == x->pParent->pParent->pLeft){
                //zig-zag rotation
                rotateLeft(x->pParent);
                rotateRight(x->pParent);
        }
        else{
                // zag-zig rotation 
                rotateRight(x->pParent);
                rotateLeft(x->pParent);
        }
    }
}
Node* insertRec(Node* curr,Node* parent, Node* p){
    if(curr == NULL) {
        p->pParent = parent;
        return p;
    }
    if(p->val >= curr->val){
        curr->pRight = insertRec(curr->pRight, curr, p);
    }
    else{
        curr->pLeft = insertRec(curr->pLeft, curr, p);
    }
    return curr;
}
void insert(int val) {
    Node* p = new Node(val);
    if(this->root == NULL) {
        this->root = p;
        return;
    }
    this->root = insertRec(this->root, NULL, p);
    splay(p);
    
}