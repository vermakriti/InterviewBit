int Solution::uniquePaths(int A, int B) {
    if(A==1 && B==1)
        return 1;
    if(A<=0 || B<=0)
        return 0;
    return uniquePaths(A,B-1) + uniquePaths(A-1,B);
}
/*
we have to take (m - 1) steps going down and (n-1) steps going right.
so total = m-1+n-1;
         = m+n-2

*/
