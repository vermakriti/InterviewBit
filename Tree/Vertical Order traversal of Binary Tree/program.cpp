/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A){
    
    vector<vector<int>> v;
    if(!A)return v;
    
    map<int,vector<int>>m;
    queue<pair<TreeNode*,int>> q;
    q.push({A,0});
    while(!q.empty()){
        
        auto p=q.front();
        q.pop();
        
        int d=p.second;
        TreeNode*node=p.first;
        
        m[d].push_back(node->val);
        
        if(node->left)
            q.push({node->left,d-1});
        
        if(node->right)
            q.push({node->right,d+1});    
            
    }
    for(auto i:m)
        v.push_back(i.second);
    return v;    
    
    
}