int Solution::removeElement(vector<int> &A, int B) {
    int i=0,j=0;
    while(i<A.size() && j<A.size()){
        if(A[i]!=B){
            i++;
            j++;
        }
        else{
            if(A[j]!=A[i]){
                swap(A[i],A[j]);
                i++;
            }    
            j++;
        }
    }
    return i;
}
