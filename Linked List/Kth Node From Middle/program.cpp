//**********Kth Node From Middle*********//

int Solution::solve(ListNode* A, int B) {
    
    ListNode*slow=A,*fast=A,*middle;
    // finding middle of the list
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    middle=slow;
    fast=A; slow=A;
    bool flag=true;
    int len=0;
    while(fast->next!=middle){
        len++;
        if(len==B){
            flag=false;
            break;
        }
        fast=fast->next;
    }
    if(flag)return -1;
    while(fast->next!=middle){
        slow=slow->next;
        fast=fast->next;
    }
    return slow->val;
}


