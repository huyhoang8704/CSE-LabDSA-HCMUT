
// void printInorder1(AVLTree* root){
    // if(root == NULL) return;
    // printInorder1(root->pLeft);
    // cout << root->data << " ";
    // printInorder1(root->pRight);
// }

void printInorder(){
    if(root == NULL) return;
    
    Node*x = root;
    root = root->pLeft;
    printInorder();
    root = x;
    cout << root->data << " ";
    root = root->pRight;
    printInorder();
    root = x;
    
}
// bool search1(AVLTree* root, const T &value){
//     if(root == NULL) return false;
//     else if(root->data > value) return search1(root->pLeft,value);
//     else if(root->data < value) return search1(root->pRight,value);
//     else return true;
// }


bool search(const T &value){
    //return search1(root,value);
    Node* x = root;
    while(x){
        if(x->data == value) return true;
        else if(x->data > value) x = x->pLeft;
        else x =x->pRight;
    }
    return false;
}