int findPivot(vector<int>&A){
    int n=A.size();
    int low=0,high=n-1,mid;
    
    while(low<=high){
        mid=low+(high-low)/2;
        if(A[mid]>A[(mid+1)%n] && A[mid]>A[(mid+n-1)%n])
            return mid;
        if(A[mid]<A[(mid+1)%n])
            low=mid+1;
        else high=mid-1;        
    }
}

int search1(vector<int>A,int B,int l,int h){
    int low=l,high=h,mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(A[mid]==B)
            return mid;
        if(A[mid]<B)
            low=mid+1;
        else high=mid-1;        
    }
    return -1;
}

int search2(vector<int>A,int B,int l,int h){
    int low=l,high=h,mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(A[mid]==B)
            return mid;
        if(A[mid]>B)
            low=mid+1;
        else high=mid-1;        
    }
    return -1;
}
int Solution::solve(vector<int> &A, int B){
    int n=A.size();
    int idx=findPivot(A);
    int ans=search1(A,B,0,idx);
    if(ans!=-1)return ans;
    ans=search2(A,B,idx+1,n-1);
    return ans;
}
