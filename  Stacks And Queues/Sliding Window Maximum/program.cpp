vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {

    vector<int> ans;
    multiset<int> s;
    deque<int> dq;
    for(int i=0;i<B;i++){
        dq.push_back(A[i]);
        s.insert(A[i]);
    }    

    for(int i=B;i<A.size();i++){
        ans.push_back(*s.rbegin());
        s.erase(s.find(dq.front()));
        s.insert(A[i]);
        dq.pop_front();
        dq.push_back(A[i]);
    }   
    ans.push_back(*s.rbegin()); 
    return ans;
}