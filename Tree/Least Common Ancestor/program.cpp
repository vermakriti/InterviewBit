/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* LCA(TreeNode*A,int B,int C){

    if(!A)return NULL;
    if(A->val==B || A->val==C)
        return A;
    TreeNode *left = LCA(A->left,B,C);
    TreeNode *right=LCA(A->right,B,C);

    if(left && right)
        return A;
    return left ? left : right;    

} 
bool find(TreeNode*A,int val){
    if(!A)return false;
    if(A->val==val)return true;
    return find(A->left,val) | find(A->right,val); 
}
int Solution::lca(TreeNode* A, int B, int C) {
    if(!find(A,B) || !find(A,C))
        return -1;
    TreeNode*node=LCA(A,B,C);
    if(!node)return -1;
    return node->val;
}
