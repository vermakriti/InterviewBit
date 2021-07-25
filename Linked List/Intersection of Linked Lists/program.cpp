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
