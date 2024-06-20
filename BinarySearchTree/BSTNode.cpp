#include <bits/stdc++.h>
using namespace std;

class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
    //* in từ gốc xuống luân phiên trái phải , phải trái
    vector<int> levelAlterTraverse(BSTNode* root) {
        if(root == NULL) return {};
        queue<BSTNode*> q;
        vector<vector<int>> vv;
        vector<int> result;
        q.push(root);
        q.push(NULL);
        int i = 0;
        while(q.size()){
            BSTNode* tmp = q.front();
            q.pop();
            if(tmp == NULL){
                vv.push_back(result);
                result.clear();
                i++;
                if(q.size()) q.push(NULL);
                continue;
            }
            result.push_back(tmp->val);
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        int len = vv.size();
        for(int i = 0; i < len; i++){
            int length = vv[i].size();
            if(i % 2 == 0) for(int j = 0; j < length; j++) result.push_back(vv[i][j]);
            else           for(int j = length - 1; j >= 0; j--) result.push_back(vv[i][j]);
        }
        return result;
    }
    //* return value nhỏ thứ k trong cây
    void  smallest(BSTNode* root, vector<int>& result){
        if(root == NULL) return;
        smallest(root->left,result);
        result.push_back(root->val);
        smallest(root->right,result);
    }
    int kthSmallest(BSTNode* root, int k) {
        vector<int> result;
        smallest(root,result);
        return result[k - 1];
    }
    //* Hàm này trả về số lượng tất cả các nút có giá trị nằm trong khoảng [lo, hi]
    int rangeCount(BSTNode* root, int lo, int hi) {
        if(!root) return 0;
        int left = rangeCount(root ->left , lo ,hi);
        int right = rangeCount(root->right , lo , hi);
        if(root->val >= lo && root->val <= hi) return 1 + left + right;
        return left + right;
    }
    //* Hàm trả về số lượng nút cha chỉ có duy nhất 1 đứa con 
    int singleChild(BSTNode* root) {
        if(root == NULL) return 0;
        else if(root->left == NULL && root->right != NULL) return  1 + singleChild(root->right);
        else if(root->right == NULL && root->left != NULL) return  1 + singleChild(root->left);
        
        return singleChild(root->right) + singleChild(root->left);
    }
    //* Hàm trả về cây nhị phân sau khi xóa các giá trị nằm ngoài khoảng [lo, hi]
    BSTNode* find(BSTNode* root, int lo, int hi){
    if(root == NULL) return NULL;
    BSTNode* tmp = root;
    while(tmp){
        if(tmp->val >= lo && tmp->val <= hi) break;
        else if(tmp->val > hi) tmp = tmp->left;
        else tmp = tmp->right;
    }
    return tmp;
}

BSTNode* del(BSTNode* root, int lo, int hi){
    if(root == NULL) return NULL;
    else if(root->val < lo) return del(root->right,lo,hi);
    else if(root->val > hi) return del(root->left,lo,hi);
    root->left = del(root->left,lo,hi);
    root->right= del(root->right,lo,hi);
    return root;
}


BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
     root = find(root, lo, hi);
     root = del(root,lo,hi);
    return root;
}
};



int main(){

}