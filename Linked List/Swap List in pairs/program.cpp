//*******Swap List Nodes in pairs******//

ListNode* Solution::swapPairs(ListNode* A) {
    
    if(!A)return A;
    if(A->next==NULL)return A;
    ListNode*curr=A;
    ListNode*prev=NULL,*temp;

    while(curr){

        if(curr->next){

            temp=curr->next;
            curr->next=curr->next->next;
            temp->next=curr;

            if(prev==NULL){
                A=temp;
                prev=curr;
               
            }
            else {
                prev->next=temp;
                prev=curr;
            }
            curr=curr->next;
        }
        else curr=curr->next;
    }
    return A;
}