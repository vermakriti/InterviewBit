/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode*solve(const vector<int> &A,int start,int end){

    if(start>end)
        return NULL;
    int mid= start+(end-start)/2;
    TreeNode*node = new TreeNode(A[mid]);
    if(start==end)return node;
    node->left = solve(A,start,mid-1);
    node->right=solve(A,mid+1,end);
    
    return node;        
} 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n=A.size();
    if(n==0)return NULL;
    return solve(A,0,n-1);
}
