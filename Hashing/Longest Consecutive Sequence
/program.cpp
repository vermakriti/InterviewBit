int Solution::longestConsecutive(const vector<int> &A) {

    map<int,int> mp;
    for(int i=0;i<A.size();i++){
        mp[A[i]]++;
    }
    int count;
    int mx=INT_MIN;
    for(int i=0;i<A.size();i++){
        if(mp.find(A[i]-1)==mp.end()){
            int num=A[i];
            count=0;
            while(mp.find(num)!=mp.end()){
                count++;
                num++;
            }
            mx=max(mx,count);
        }
    }
    return mx;
}
