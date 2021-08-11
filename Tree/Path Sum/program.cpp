int Solution::hasPathSum(TreeNode* root, int B) {
    if(!root)return 0;
    if(!root->left && !root->right){
        if(B==root->val)
            return 1;
        else return 0;    
    }
    return hasPathSum(root->left,B-root->val) | hasPathSum(root->right,B-root->val);
}
