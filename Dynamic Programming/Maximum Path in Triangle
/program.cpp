int dp[1005][1005];
int maxPath(int i,int j,vector<vector<int> > &A){

    if(i>=A.size() || j>=A[i].size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans = max(maxPath(i+1,j,A)+A[i][j],maxPath(i+1,j+1,A)+A[i][j]);
    return dp[i][j]=ans;        
}
int Solution::solve(vector<vector<int> > &A) {
   
    int ans=INT_MIN;
    memset(dp,-1,sizeof dp);
    ans=max(ans,maxPath(0,0,A));
      
    return ans;    
}
