#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	vector<int> A(n),left(n),right(n);
	stack<pair<int,int>>st;

	for(int i=0;i<n;i++)
		cin>>A[i];

    // next right smaller element
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().first>A[i]){
            right[st.top().second]=i;
            st.pop();
        }
        st.push({A[i],i});
    }
    while(!st.empty()){
        right[st.top().second]=n;
        st.pop();
    }
    // next left smaller element
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top().first>A[i]){
            left[st.top().second]=i;
            st.pop();
        }
        st.push({A[i],i});
    }
    while(!st.empty()){
        left[st.top().second]=-1;
        st.pop();
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,A[i]*(right[i]-left[i]-1));
    }
    cout<<ans<<"\n";
    return 0;

}