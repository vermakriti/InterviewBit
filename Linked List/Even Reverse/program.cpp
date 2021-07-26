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
ListNode* Solution::solve(ListNode* A) {
    
    if(!A || !A->next || !A->next->next)
        return A;    
    ListNode*even=A->next,*odd=A,*odd_next=NULL,*even_next=NULL;
    ListNode*even_head=even,*odd_head=odd;

    bool flag=true; //odd position
    A=A->next->next;
    while(A){

        if(flag){
            odd->next=A;
            odd=A;
            flag=false;
        }
        else{
            even->next=A;
            even=A;
            flag=true;
        }
        A=A->next;
    }
    odd->next=NULL;
    even->next=NULL;

    even=reverse(even_head);
    odd=odd_head;

    while(odd && even){
        odd_next=odd->next;
        even_next=even->next;
        odd->next=even;
        even->next=odd_next;
        odd=odd_next;
        even=even_next;
    }
    A=odd_head;
    return A;
}
