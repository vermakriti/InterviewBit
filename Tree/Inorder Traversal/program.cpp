/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    stack<TreeNode*> st;
    TreeNode*curr=A,*top;
    vector<int> v;
    while(curr!=NULL || !st.empty()){
        
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        top=st.top();
        st.pop();
        v.push_back(top->val);
        curr=curr->right;
    }
    return v;
}
