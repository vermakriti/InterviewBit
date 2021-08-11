void dfs(TreeNode*root,int B,vector<vector<int>> &v,vector<int> a,int sum){
    
    if(!root)return;
    if(root->left==NULL && root->right==NULL){
        sum+=root->val;
        if(sum==B){
            a.push_back(root->val);
            v.push_back(a);
        }    
        
    }
    sum+=root->val;
    a.push_back(root->val);
    
    dfs(root->left,B,v,a,sum);
    dfs(root->right,B,v,a,sum);
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    
    vector<vector<int>> v;
    vector<int> a;
    if(!A)return v;
    dfs(A,B,v,a,0);
    return v;
}
