//**********Reverse Link List II*********//

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {

    ListNode*curr=NULL,*prev=NULL,*next,*prevNdode=NULL,*nthNode,*mthNode,*head=A;
    int len=0;
    while(head){
        len++;
        if(len==B-1){
            prevNdode=head;
        }
        if(len==B){
            next=head;
            mthNode=head;
        }
        if(len==C){
            nthNode=head;
            break;
        }
        head=head->next;
    }
    nthNode=nthNode->next;
    while(next!=nthNode){
        prev=curr;
        curr=next;
        next=next->next;
        curr->next=prev;
    }
    if(prevNdode)
        prevNdode->next=curr;
    else A=curr;
    mthNode->next=nthNode;
    return A;

}