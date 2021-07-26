/******* using stack******/
int Solution::solve(string A) {

    stack<char> st;
    for(int i=0;i<A.size();i++){

        if(A[i]=='(')
            st.push(A[i]);
        else {
            if(st.empty())
                return 0;
            if(st.top()=='(')
                st.pop();
            else return 0;        
        }    
    }
    if(st.empty())
        return 1;
    return 0;    
}

/***********Another Method *******/
int Solution::solve(string A) {

    int open=0;
    int close=0;
    int balance=0;
    for(int i=0;i<A.size();i++){
        if(A[i]=='(')
            open++;
        else close++;

        if(open==close){
            balance+=2*open;
            open=0;
            close=0;
        }    
        else if(close>open)
            close=0;
        else {
            balance+=2*close;
            close=0;
            open-=close;
        }          
    }
    if(A.size()==balance)return 1;
    return 0;
}
