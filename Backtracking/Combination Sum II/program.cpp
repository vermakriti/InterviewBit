/************Combination Sum II ********/
#include<bits/stdc++.h>
using namespace std;

void combinationSum(int i,int target,vector<int> a,set<vector<int>> &s,vector<int>temp){

	if(i>=a.size() || target<0)
		return;
	if(target==0){
		s.insert(temp);
		return;
	}
	for(int j=i;j<a.size();j++){
		temp.push_back(a[j]);
		combinationSum(j+1,target-a[j],a,s,temp);
		temp.pop_back();
	}
}
int main(){

	int n,target;
	cin>>n >> target;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>> a[i];
	sort(a.begin(),a.end());

	vector<vector<int>> ans;
	vector<int> temp;
	set<vector<int>> s;

	combinationSum(0,target,a,s,temp);
	for(auto v:s)
		ans.push_back(v);
	for(auto v:ans){
		for(auto ele:v)
			cout<<ele<<" ";
		cout<<"\n";
	}
	return 0;
}

