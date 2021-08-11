vector<int> Solution::solve(vector<int> &A, int B) {
    if(B==0)return A;
    int n=A.size();
    vector<int> v(n+2);
    for(int i=0;i<A.size();i++)
        v[A[i]]=i;
    for(int i=0;i<A.size();i++){
        if(B==0)break;
        if(A[i]!=n-i){
            v[A[i]]=v[n-i];
            swap(A[i],A[v[n-i]]);
           
            B--;
        }
    }
    return A;

}
