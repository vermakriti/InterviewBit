/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<int,int> mp; 
TreeNode* solve(vector<int> &pre, vector<int> &ino,int start,int end,int &idx){

    if(start>end)
        return NULL;
    TreeNode*node= new TreeNode(pre[idx++]);
    if(start==end)
        return node;
    node->left = solve(pre,ino,start,mp[node->val]-1,idx);
    node->right = solve(pre,ino,mp[node->val]+1,end,idx);

    return node;

}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {

    for(int i=0;i<B.size();i++)
        mp[B[i]]=i;
    int idx=0;    
    return solve(A,B,0,B.size()-1,idx);    
}
