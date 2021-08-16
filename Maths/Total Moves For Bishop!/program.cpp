int Solution::solve(int A, int B) {
    int x[]={1,1,-1,-1};
    int y[]={1,-1,1,-1};

    int ans=0;
    for(int k=0;k<4;k++){
        int i=A+x[k];
        int j=B+y[k];
        while(i>=1 && i<=8 && j>=1 && j<=8){
            ans++;
            i+=x[k];
            j+=y[k];
        }
    }
    return ans;
}
