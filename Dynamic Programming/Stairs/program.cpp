int dp[10005];
int solve(int i,int A){

    if(i>A)
        return 0;
    if(i==A)
        return 1;
    if(dp[i]!=-1)
        return dp[i];
    int ans= solve(i+1,A) + solve(i+2,A);
    return dp[i]=ans;            
}
int Solution::climbStairs(int A) {
    memset(dp,-1,sizeof dp);
    return solve(0,A);
}