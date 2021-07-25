//*********Palindrome List*********//
ListNode*reverse(ListNode*A){

    ListNode*curr=NULL,*prev=NULL,*next=A;
    while(next){
        prev=curr;
        curr=next;
        next=next->next;
        curr->next=prev;
    }
    A=curr;
    return A;
}
int Solution::lPalin(ListNode* A) {
    //base case
    if(!A || !A->next)return 1;
    // finding middle of the list
    ListNode*slow=A,*fast=A,*prev=NULL,*curr1,*curr2;
    while(slow && fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;
    curr1=A;
    curr2=reverse(slow);
    while(curr1 && curr2){

        if(curr1->val!=curr2->val)
            return 0;
        curr1=curr1->next;
        curr2=curr2->next;    
    }
    if(!curr1 && !curr2)
        return 1;
    if(!curr1 && !curr2->next)
        return 1;
    if(!curr2 && !curr1->next)   
        return 1;
    return 0;     
}
