ListNode* Solution::deleteDuplicates(ListNode* A) {

    ListNode*curr=A;

    while(curr){

        if(curr->next && curr->val == curr->next->val){
            curr->next=curr->next->next;
        }
        else curr=curr->next;
    }
    return A;
}
