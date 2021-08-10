int Solution::sqrt(int A) {
    if(A==0 || A==1)
        return A;
    int ans=0;
    int low=1,high=A,mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(mid*mid==A){
            ans=mid;
            break;
        }
        if(mid<=A/mid){
            ans=mid;
            low=mid+1;
        }    
        else high=mid-1;    
    }
    return ans;
}
