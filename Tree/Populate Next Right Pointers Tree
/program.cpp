/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {

    queue<TreeLinkNode*> q;
    TreeLinkNode*prev;
    q.push(A);

    while(!q.empty()){
       
        int ss=q.size();
        int i=1;
        while(i<=ss){
            TreeLinkNode*curr=q.front();
            q.pop();
            if(i==1){
                prev=curr;
            }
            else{
                prev->next=curr;
                prev=curr;
            }
            i++;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);    
        }
        prev->next=nullptr;
    }
}
