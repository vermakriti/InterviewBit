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

//*********Intersection of Linked Lists******//

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {

    int lenA=0;
    int lenB=0;
    ListNode*currA=A,*currB=B;

    while(currA){
        lenA++;
        currA=currA->next;
    }
    while(currB){
        lenB++;
        currB=currB->next;
    }
    int len_diff=abs(lenA-lenB)+1;
    currA=A;
    currB=B;
    if(lenA>lenB){
        while(currA){
            len_diff--;
            if(len_diff==0)
                break;
            currA=currA->next;    
        }
    }
    else{
        while(currB){
            len_diff--;
            if(len_diff==0)
                break;
            currB=currB->next;    
        }
    }
    while(currA && currB){
        if(currA==currB)
            return currA;
        currA=currA->next;
        currB=currB->next;    
    }
    return NULL;
}

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

//***********Even Reverse*********//
