void solve(int i,int n,int k,vector<vector<int>> &ans,vector<int> temp){
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }
    if(i>n || temp.size()>k)
        return;
    for(int j=i;j<=n;j++){
        temp.push_back(j);
        solve(j+1,n,k,ans,temp);
        temp.pop_back();
    }    
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(1,A,B,ans,temp);
    return ans;
}
