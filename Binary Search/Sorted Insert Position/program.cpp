int Solution::searchInsert(vector<int> &A, int B) {
    if(A[0]>B)return 0;
    int n=A.size(),low=0,high=n-1,mid,ans=0;
    bool flag=false;
    while(low<=high){
       mid=low + (high-low)/2;
        if(A[mid]==B){
            ans=mid;
            flag=true;
            break;
        }
        if(A[mid]<B){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(flag)return ans;
    return ans+1;
}
