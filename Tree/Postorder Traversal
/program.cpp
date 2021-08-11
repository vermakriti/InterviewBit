/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {

    vector<int> ans;
    stack<TreeNode*> st;


    st.push(A);

    while(!st.empty()){

        TreeNode*curr=st.top();
        st.pop();

        ans.push_back(curr->val);

        if(curr->left)
            st.push(curr->left);
        if(curr->right)
            st.push(curr->right);    
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
