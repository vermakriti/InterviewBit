/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {

    vector<int> v;
    queue<TreeNode*> q;
    stack<TreeNode*> st;
    q.push(A);

    while(!q.empty()){

        TreeNode*curr=q.front();
        q.pop();

        st.push(curr);

        if(curr->right)
            q.push(curr->right);
        if(curr->left)
            q.push(curr->left);    
    }
    while(!st.empty()){
        TreeNode*curr=st.top();
        v.push_back(curr->val);
        st.pop();
    }
    return v;
}
