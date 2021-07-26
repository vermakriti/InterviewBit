void solve(int i,vector<int> &A,vector<vector<int>> &ans,vector<int> temp){
    ans.push_back(temp);
    if(i>=A.size())
        return;
    for(int j=i;j<A.size();j++){
        temp.push_back(A[j]);
        solve(j+1,A,ans,temp);
        temp.pop_back();
    }    
}
vector<vector<int> > Solution::subsets(vector<int> &A) {

    sort(A.begin(),A.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0,A,ans,temp);
    return ans;    
}
