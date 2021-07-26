vector<int> Solution::prevSmaller(vector<int> &A) {

    stack<pair<int,int>> s;
    int n=A.size();
    vector<int> v(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top().first>A[i]){
            int idx=s.top().second;
            v[idx]=A[i];
            s.pop();
        }
        s.push({A[i],i});
    }

    while(!s.empty()){
         int idx=s.top().second;
        v[idx]=-1;
        s.pop();
    }
    return v;
}
