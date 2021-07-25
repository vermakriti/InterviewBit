//***********Add Two Numbers as Lists*********//

ListNode* reverse(ListNode*head){

    ListNode*prev=NULL,*curr=NULL,*next=head;
    while(next){
        prev=curr;
        curr=next;
        next=next->next;
        curr->next=prev;
    }
    head=curr;
    return head;
} 
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {

    ListNode*head=new ListNode(0),*tail=head;
    int c=0;

    while(A && B){
        ListNode*node = new ListNode((A->val+B->val+c)%10);
        c=(A->val+B->val+c)/10;
        tail->next=node;
        tail=node;
        A=A->next;
        B=B->next;
    }

    while(A){
        ListNode*node=new ListNode((A->val+c)%10);
        c=(A->val+c)/10;
        tail->next=node;
        tail=node;
        A=A->next;   
    }

    while(B){
        ListNode*node=new ListNode((B->val+c)%10);
        c=(B->val+c)/10;
        tail->next=node;
        tail=node;
        B=B->next;
    }
    if(c){
        ListNode*node=new ListNode(c);
        tail->next=node;
        tail=node;
    }
    head=head->next;
    return head;
}
