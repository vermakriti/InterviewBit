//**********Merge Two Sorted Lists*******//

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {

    ListNode*head=new ListNode(0),*tail=head;
    while(A && B){

        if(A->val<B->val){
           tail->next=A;
           tail=A;
           A=A->next;
        }
        else{
            tail->next=B;
            tail=B;
            B=B->next;
        }
    }
    while(A){
        tail->next=A;
        tail=A;
        A=A->next;
    }
    while(B){
        tail->next=B;
        tail=B;
        B=B->next;
    }
    tail->next=NULL;
    head=head->next;
    return head;
}