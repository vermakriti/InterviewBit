//************Remove Nth Node from List End******//

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {

    if(!A)return A;
    int len=0;
    ListNode*slow=A,*fast=A,*prev=NULL;
    bool flag=true;

    while(fast){
        len++;
        if(len==B){
            flag=false;
            break;
        }
        fast=fast->next;
    }
    if(flag){
        A=A->next;
        return A;
    }
    while(fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next;
    }
    if(prev==NULL){
        A=A->next;
        return A;
    }
    prev->next=slow->next;
    return A;
}