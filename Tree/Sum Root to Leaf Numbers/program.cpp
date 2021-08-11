int sum(treenode* root,int s){
    if(!root)return 0;
    if(!root->left && !root->right){
        s=(s*10)%1003;
        s=(s+root->val)%1003;
        return s;
    }
    s=(s*10)%1003;
    s=(s+root->val)%1003;
    return (sum(root->left,s)+ sum(root->right,s))%1003;

} 
int sumNumbers(treenode* A) {
    return sum(A,0);
}
