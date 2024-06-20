#ifndef __Binary_Search_Trees_H__
#define __Binary_Search_Trees_H__

#include "main.h"

//! Node của cây tìm kiếm nhị phân
template <typename E> 
class BSTNode{
public:
    E Key;        //* key
    BSTNode* left;   //* value
    BSTNode* right;   //* right
public:
    BSTNode(const E& Key, BSTNode* left = nullptr, BSTNode* right = nullptr)
    : Key(Key), left(left), right(right) {}
};

//! INSERT NODE
template <typename E> 
BSTNode<E>* insertBTSNode(BSTNode<E>* root,const E& TKey );

//! DELETE NODE
template <typename E> 
BSTNode<E>* deleteBTSNode(BSTNode<E>* root,const E& TKey);

//! FIND NODE
template <typename E> 
bool findBTSNode(BSTNode<E>* root,const E& TKey);

//! PREODER - TIỀN THỨ TỰ
template <typename E> 
void preoderBTS(BSTNode<E>* root);

//! INODER - TRUNG THỨ TỰ 
template <typename E> 
void inoderBTS(BSTNode<E>* root);

//! POSTODER - HẬU THỨ TỰ
template <typename E> 
void postoderBTS(BSTNode<E>* root);

//! HEIGHT TREE
template <typename E> 
int heightBTS(BSTNode<E>* root);

//! BFS - DUYỆT CHIỀU RỘNG 
template <typename E> 
void bfsBTS(BSTNode<E>* root);

//! CHECK BTS - kiếm tra có phải cây nhị phân hay không
template <typename E> 
bool isBST(BSTNode<E>* root,E minValue,E maxValue);

#endif // __Binary_Search_Trees_H__