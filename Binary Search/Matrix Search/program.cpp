int Solution::searchMatrix(vector<vector<int> > &A, int B) {

    int row=A.size(),col=A[0].size();
    int r=0,c=col-1;

    while(r<row && c>=0){
        if(A[r][c]==B)
            return 1;
        if(A[r][c]>B)
            c--;
        else r++;    
    }
    return 0;
}
