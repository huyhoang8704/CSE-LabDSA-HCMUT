#include <iostream>
using namespace std;

class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        }
//* Tính tổng đường đi dài nhất của cây
int longestPathSumUtil(BTNode* root, int& maxLen) {
    if (root == nullptr) {
        maxLen = 0;
        return 0;
    }

    int leftMaxLen, rightMaxLen; // độ dài
    int leftSum = longestPathSumUtil(root->left, leftMaxLen); // tổng
    int rightSum = longestPathSumUtil(root->right, rightMaxLen); // tổng

    maxLen = max(leftMaxLen, rightMaxLen) + 1;

    if (leftMaxLen == rightMaxLen)     return max(leftSum, rightSum) + root->val;
    else if (leftMaxLen > rightMaxLen) return leftSum + root->val;
    else                               return rightSum + root->val;
    
}
int longestPathSum(BTNode* root) {
    int maxLen = 0;
    return longestPathSumUtil(root, maxLen);
}
//* cách 2
void longestPathSumRec(BTNode* root, int sum, int height, int &heightMax, int& result) {
    if (!root) {
        if (heightMax < height) {
            heightMax = height;
            result = sum;
        } else if (heightMax == height && result < sum)
            result = sum;
        return;
    }
     longestPathSumRec(root->left, sum + root->val, height + 1, heightMax,result);
     longestPathSumRec(root->right, sum + root->val, height + 1, heightMax,result);
}
int longestPathSum(BTNode* root) {
    int heightMax = 0;
    int result = -9999;
    longestPathSumRec(root, 0, 0, heightMax,result);
    return result;
}
//* Tìm node cha của Node a và Node b
int lowestAncestor(BTNode* root, int a, int b) {
    if(root == NULL) return -9999;
    if(root->val == a){
       return root->val;
    }
    else if(root->val == b){
        return root->val;
    }
    int left = lowestAncestor(root->left,a,b);
    int right = lowestAncestor(root->right,a,b);
    if(left != -9999 && right != -9999) return root->val;
    else if(left != -9999) return left;
    return right;
}
//* Tổng tất cả các đường đi của cây
long long sumDigitPath(BTNode* root, long long sum = 0) {
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return (sum*10+ root->val) % 27022001;
    sum = (sum*10) % 27022001;
    return (sumDigitPath(root->left,sum + root->val)% 27022001 +  sumDigitPath(root->right,sum + root->val)% 27022001)% 27022001;
    
}

};

int main(){

}
