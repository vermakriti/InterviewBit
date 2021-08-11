/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(!A)return A;
    TreeNode*left=A->left;
    A->left=A->right;
    A->right=left;
    invertTree(A->left);
    invertTree(A->right);
    return A;
    
}