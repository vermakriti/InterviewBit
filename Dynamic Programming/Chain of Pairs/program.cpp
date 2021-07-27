int dp[10005];
int maxLength(int i,vector<vector<int> > &A){

    if(i>=A.size())
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int ans=0;    
    for(int j=i+1;j<A.size();j++){
        if(A[j][0]>A[i][1])
            ans=max(ans,maxLength(j,A)+1);
    }  
    return dp[i]=ans;      
}
int Solution::solve(vector<vector<int> > &A) {
    memset(dp,-1,sizeof dp);

    int ans=0;
    for(int i=0;i<A.size();i++)
        ans=max(ans,maxLength(i,A));
    return ans+1;    
}
