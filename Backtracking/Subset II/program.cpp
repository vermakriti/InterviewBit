void solve(int i,vector<int> &A,set<vector<int>> &s,vector<int>temp){

    s.insert(temp);
    if(i>=A.size())return;
    for(int j=i;j<A.size();j++){
        temp.push_back(A[j]);
        solve(j+1,A,s,temp);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {

    vector<vector<int>> ans;
    vector<int> temp;
    if(A.size()==0){
        ans.push_back(temp);
        return ans;
    }    
    sort(A.begin(),A.end());
    set<vector<int>> s;
    
    solve(0,A,s,temp);
    for(auto a:s){
        ans.push_back(a);
    }
    return ans;
}
