
//***********Rotate List**********//
int length(ListNode*A){

    int length=0;
    ListNode*curr=A;
    while(curr){
        length++;
        curr=curr->next;
    }
    return length;
} 
ListNode* Solution::rotateRight(ListNode* A, int B) {

	//Base Case
    if(!A)return A;
    ListNode*slow=A,*fast=A,*prev=NULL;

    int len=B%length(A);
    if(len==0)return A;

    while(fast){
        len--;
        if(len==0)
            break; 
        fast=fast->next;    
    }
    while(fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next;
    }
    if(prev==NULL) return A;
    fast->next=A;
    A=slow;
    prev->next=NULL;
    return A;
}