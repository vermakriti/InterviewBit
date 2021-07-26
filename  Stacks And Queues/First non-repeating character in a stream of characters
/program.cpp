string Solution::solve(string A) {
    
    deque<char> dq;
    map<char,int> mp;
    string s="";
    for(int i=0;i<A.size();i++){
        mp[A[i]]++;
        dq.push_back(A[i]);
        while(!dq.empty()){

            if(mp[dq.front()]>1)
                dq.pop_front();
            else{
                s+=dq.front();
                break;   
            }     
        } 
        if(dq.empty())
            s+='#';
        
    }
    return s;
}
