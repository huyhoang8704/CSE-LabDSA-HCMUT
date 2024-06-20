//Helping functions
Node* rotateLeft(Node* root){
    Node* tempPtr = root->pRight;
    root->pRight = tempPtr->pLeft;
    tempPtr->pLeft = root;
    return tempPtr;
}
Node* rotateRight(Node* root){
    Node* tempPtr = root->pLeft;
    root->pLeft = tempPtr->pRight;
    tempPtr->pRight = root;
    return tempPtr;
    
}

Node* leftBalance(Node* & root, bool & taller){
    Node* leftTree = root->pLeft;
    if(leftTree->balance == LH){
        root = rotateRight(root);
        root->pRight->balance = EH;
        leftTree->balance = EH;
        taller = false;
    }
    else{
        Node* rightTree = leftTree->pRight;
        if(rightTree->balance == LH){
            root->balance = RH;
            leftTree->balance = EH;
        }
        else if(rightTree->balance == EH){
            leftTree->balance = EH;
            root->balance = EH;
        }
        else{
            root->balance = EH;
            leftTree->balance = LH;
        }
        rightTree->balance = EH;
        root->pLeft = rotateLeft(leftTree);
        root = rotateRight(root);
        taller =false;
    }
    return root;
}

Node* rightBalance(Node* & root, bool & taller){
    Node* rightTree = root->pRight;
    if(rightTree->balance == RH){
        root = rotateLeft(root);
        root->pLeft->balance = EH;
        rightTree->balance= EH;
        taller = false;
    }
    else{
        Node* leftTree = rightTree->pLeft;
        if(leftTree->balance == RH){
            root->balance = LH;
            rightTree->balance = EH;
        }
        else if(leftTree->balance == EH){
            rightTree->balance = EH;
            root->balance = EH;
        }
        else{
            root->balance = EH;
            rightTree->balance = RH;
        }
        leftTree->balance = EH;
        root->pRight = rotateRight(rightTree);
        root = rotateLeft(root);
        taller = false;
    }
    return root;
}

Node *insertRec(Node* & root, Node* newPtr, bool& taller){
    if(root == NULL){
        root = newPtr;
        taller = true;
        return root;
    }
    if(newPtr->data < root->data){
        root->pLeft = insertRec(root->pLeft, newPtr, taller);
        if(taller){
            if(root->balance == LH){ // case 1: LH
                root = leftBalance(root, taller);
            }
            else if(root->balance == EH){ // case 2 : EH
                root->balance = LH;    
            }
            else{ // case 3: RH
                root->balance = EH;
                taller = false;
            }
        }
    }
    //////////////////////////////
    else{
        root->pRight = insertRec(root->pRight, newPtr, taller);
        if(taller){
            if(root->balance == RH) {
                root = rightBalance(root, taller);
            }
            else if(root->balance == EH){
                root->balance = RH;
            }
            else{
                root->balance = EH;
                taller = false;
            }
        }
    }
    return root;
}
void insert(const T &value){
    //TODO
    Node* p = new Node(value);
    bool taller = false;
    insertRec(this->root,p, taller);
}





