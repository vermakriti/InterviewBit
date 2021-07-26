int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int i=0,j=1;
    while(j<A.size() && i<A.size()){

        if(A[j]-A[i]==B && i!=j)
            return 1;
        if(A[j]-A[i]<B)
            j++;
        else i++;        
    }
    return 0;
}
