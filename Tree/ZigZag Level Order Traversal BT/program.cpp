/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {

    vector<vector<int>> v;
    queue<TreeNode*> q;
    q.push(A);
    bool flag=false;

    while(!q.empty()){

        int ss=q.size();
        vector<int> a;
        while(ss--){
            TreeNode*curr=q.front();
            q.pop();
            a.push_back(curr->val);

            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);    
        }
        if(flag){
            reverse(a.begin(),a.end());
            flag=false;
        }
        else flag=true;
        v.push_back(a);
    }
    return v;
}
