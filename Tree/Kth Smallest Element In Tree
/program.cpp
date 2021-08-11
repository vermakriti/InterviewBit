int Solution::kthsmallest(TreeNode* A, int B) {
    TreeNode*curr=A;
    stack<TreeNode*> st;
    while(curr || !st.empty()){

        while(curr){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        if(B==1)return curr->val;
        B--;
        curr=curr->right;
    }
}