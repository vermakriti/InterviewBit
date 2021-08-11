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
TreeNode*solve(vector<int> &pos, vector<int> &ino,int start,int end ,int &idx) {

    if(start>end)
        return NULL;
    TreeNode*node=new TreeNode(pos[idx--]);
    if(start==end)
        return node;
    node->right=solve(pos,ino,mp[node->val]+1,end,idx);
    node->left=solve(pos,ino,start,mp[node->val]-1,idx);

    return node;

}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    for(int i=0;i<B.size();i++)
        mp[A[i]]=i;
    int idx=B.size()-1;
    return solve(B,A,0,B.size()-1,idx);     
}
