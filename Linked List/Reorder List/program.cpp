//************Reorder List*********//

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
ListNode* Solution::reorderList(ListNode* A) {

    ListNode*slow=A,*fast=A,*next1,*next2;
    // finding middle element of list
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode*curr1=A,*curr2=slow->next;
    slow->next=NULL;

    curr2=reverse(curr2);

    while(curr1 && curr2){
        next1=curr1->next;
        curr1->next=curr2;
        
        next2=curr2->next;
        curr2->next=next1;

        curr1=next1;
        curr2=next2;
    }
    return A;
}
