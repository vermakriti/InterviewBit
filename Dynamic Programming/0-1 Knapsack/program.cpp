int dp[1005][1005];
int knapsack(int i,vector<int> &A, vector<int> &B, int C){
    if(i>=A.size() || C<0)
        return 0;
    if(dp[i][C]!=-1)
        return dp[i][C];
    int ans;
    if(B[i]<=C)
        ans=max(knapsack(i+1,A,B,C-B[i])+A[i],knapsack(i+1,A,B,C));
    else ans = knapsack(i+1,A,B,C);
    return dp[i][C]=ans;            
}
int Solution::solve(vector<int> &A, vector<int> &B, int C) {

    memset(dp,-1,sizeof dp);
    return knapsack(0,A,B,C);
}
