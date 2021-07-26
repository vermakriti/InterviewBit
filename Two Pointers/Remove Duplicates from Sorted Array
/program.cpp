int Solution::removeDuplicates(vector<int> &A) {
    
    if(A.size()==0 || A.size()==1)
        return A.size();
    int i=0,j=1;
    while(i<A.size() && j<A.size()){
        if(A[i]!=A[j]){
            swap(A[i+1],A[j]);
            i++;    
            j++;
        }
        else{
            j++;
        }
    }    
    return i+1;
}
