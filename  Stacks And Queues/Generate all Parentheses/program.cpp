int Solution::isValid(string A) {

    stack<char> st;
    for(int i=0;i<A.size();i++){

        if(A[i]=='(')
            st.push(A[i]);
        else if(A[i]=='{')
            st.push(A[i]);
        else if(A[i]=='[')
            st.push(A[i]);
        else{
            if(st.empty())
                return 0;
            if(st.top()=='(' && A[i]==')')
                st.pop();
            else if(st.top()=='{' && A[i]=='}')
                st.pop();
            else if(st.top()=='[' && A[i]==']')
                st.pop();
            else return 0;                
        }            
    }
    if(st.empty())
        return 1;
    return 0;    
}
