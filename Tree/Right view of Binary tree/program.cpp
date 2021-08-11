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
    q.push(A);

    while(!q.empty()){
        int size=q.size();
        int i=1;
        while(i<=size){
            TreeNode *curr = q.front(); 
            q.pop();
            if(i==size){
                v.push_back(curr->val);
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);    
            i++;    

        }
        
    }
   
    return v;
}
