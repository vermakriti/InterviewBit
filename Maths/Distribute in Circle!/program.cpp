int Solution::solve(int A, int B, int C) {

    int require=(B-C+1);// require candy to go to end point of circle
    if(A<=require){
        int pos=C;
        A-=1;
        while(pos && A--){
            pos++;
        }
        return pos;
    }
    A-=require;
    return A%B;
}
