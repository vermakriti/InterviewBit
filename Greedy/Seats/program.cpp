int Solution::seats(string A) {
    vector<int> v;
    int mod=10000003;
    for(int i=0;i<A.size();i++){
        if(A[i]=='x')
            v.push_back(i);
    }
    int n=v.size();
    if(n==1 || n==0)return 0;

    int idx=v[n/2],ans=0,left,right;
    left=idx-1;
    right=idx+1;
    for(int i=0;i<A.size();i++){
        if(A[i]=='x'){
            if(i<idx){
                ans= ans%mod + (left-i)%mod;
                left--;
            }
            else if(i>idx){
                ans= ans%mod + (i-right)%mod;
                right++;
            }
        }
    }
    return ans;

}
