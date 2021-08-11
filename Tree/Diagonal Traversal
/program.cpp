void help(TreeNode* root, map<int, vector<int>>& mp, int v){
    if(!root)return;
    mp[v].push_back(root->val);
    help(root->left, mp, v + 1); // pre order traversal
    help(root->right, mp, v);
    
}
vector<int> Solution::solve(TreeNode* A) {
    map<int, vector<int>> mp; // vertical : vector
    help(A, mp, 0); // 0 represents vertical
    vector<int> ans;
    for(auto p : mp){
        for(int x : p.second){
                ans.push_back(x);
        }
    }
    return ans;
}

