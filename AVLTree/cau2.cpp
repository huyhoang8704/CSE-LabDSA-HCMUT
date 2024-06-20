//Helping functions

Node* deleteRightBalance(Node*& root, bool & shorter){
    if(root->balance == LH){
        root->balance = EH ;
    }
    else if(root->balance == EH){
        root->balance = RH;
        shorter = false;
    }
    else{
        Node* rightTree = root->pRight;
        if(rightTree->balance == LH){
            Node*leftTree = rightTree->pLeft;
            if(leftTree->balance == LH){
                rightTree->balance = RH;
                root->balance = EH;
            }
            else if(leftTree->balance == EH){
                root->balance = LH;
                rightTree->balance = EH;
            }
            else{
                root->balance = LH;
                rightTree->balance = EH;
            }
            leftTree->balance = EH;
            root->pRight = rotateRight(rightTree);
            root = rotateLeft(root);
        }
        else{
            if(rightTree->balance != EH){
                root->balance = EH;
                rightTree->balance = EH;
            }
            else{
                root->balance = RH;
                rightTree->balance = LH;
                shorter = false;
            }
            root = rotateLeft(root);
        }
       
    }
    return root;
}
Node* deleteLeftBalance(Node*& root, bool & shorter){
    if(root->balance == RH){
        root->balance = EH ;
    }
    else if(root->balance == EH){
        root->balance = LH;
        shorter = false;
    }
    else{
        Node* leftTree = root->pLeft;
        if(leftTree->balance == RH){
            Node* rightTree = leftTree->pRight;
            if(rightTree->balance == RH){
                leftTree->balance = LH;
                root->balance = EH;
            }
            else if(rightTree->balance == EH){
                root->balance = RH;
                leftTree->balance = EH;
            }
            else{
                root->balance = RH;
                leftTree->balance = EH;
            }
            rightTree->balance = EH;
            root->pLeft = rotateLeft(leftTree);
            root = rotateRight(root);
        }
        else{
            if(leftTree->balance != EH){
                root->balance = EH;
                leftTree->balance = EH;
            }
            else{
                root->balance = LH;
                leftTree->balance = RH;
                shorter = false;
            }
            root = rotateRight(root);
        }
       
    }
    return root;
}
Node* AVLDelete(Node* & root, const T & deleteKey, bool& shorter, bool &success){
        if(root == NULL) {
            shorter = false;
            success = false;
            return NULL;
        }
        if(deleteKey < root->data){
            root->pLeft = AVLDelete(root->pLeft, deleteKey, shorter, success);
            if(shorter){
                root = deleteRightBalance(root, shorter);
            } 
    
        }
        else if(deleteKey > root->data) {
            root->pRight = AVLDelete(root->pRight, deleteKey, shorter, success);
            if(shorter){
                root = deleteLeftBalance(root, shorter);
            }
        }
        else{
            Node* deleteNode = root;
            if(deleteNode->pRight == NULL){
                Node* newRoot = root->pLeft;
                success = true;
                shorter = true;
                delete deleteNode;
                return newRoot;
            } 
            else if(deleteNode->pLeft == NULL){
                Node* newRoot = root->pRight;
                success = true;
                shorter = true;
                delete deleteNode;
                return newRoot;
            }
            else{
                Node* exchPtr = root->pLeft;
                while(exchPtr->pRight != NULL){
                    exchPtr = exchPtr->pRight;
                }
                root->data =exchPtr->data;
                root->pLeft = AVLDelete(root->pLeft,exchPtr->data, shorter, success);
                if(shorter){
                    root = deleteRightBalance(root, shorter);
                }
            }
        }
        return root;
    }
    
void remove(const T &value){
   bool shorter = false;
   bool success = false;
   this->root = AVLDelete(this->root,value, shorter, success);
}