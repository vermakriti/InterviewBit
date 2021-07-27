int dp[2505];
int fun(int i, vector<int> A){

    if(i>=A.size())
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int ans=0;
    for(int j=i+1;j<A.size();j++){
        if(A[j]>A[i])
            ans=max(ans,fun(j,A)+1);
    }
    return dp[i]=ans;
}
int Solution::lis(const vector<int> &A){
    
    int ans=0;
     memset(dp,-1,sizeof dp);
    for(int i=0;i<A.size();i++){
       ans=max(ans,fun(i,A));
    }
    return ans+1;
}
