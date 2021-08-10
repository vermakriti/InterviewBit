int Solution::solve(vector<int> &A, int B) {
    if(A.size()==1){
        if(A[0]!=B)return 0;
        return 1;
    }
    int low=0,high=A.size()-1,mid,ans=0;
    int n=A.size();

    while(low<=high){
        mid=low+(high-low)/2;
        if(A[mid]==B){
            ans=mid;
        }
        if(A[mid]<=B){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans+1;
}
