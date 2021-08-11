int Solution::majorityElement(const vector<int> &A) {
   
    map<int,int> mp;
    int n=A.size();
    for(int i=0;i<A.size();i++)
        mp[A[i]]++;
    for(auto i:mp){
        if(i.second>n/2)
            return i.first;
    }    
}
