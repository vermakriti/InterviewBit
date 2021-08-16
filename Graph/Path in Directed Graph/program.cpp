void dfs(int node,vector<int> adj[],vector<int> &visited){
    visited[node]=1;
    for(auto child:adj[node]){
        if(!visited[child]){
            dfs(child,adj,visited);
        }
    }
}
int Solution::solve(int A, vector<vector<int> > &B) {

    vector<int> adj[A+2];
    vector<int> visited(A+2,0);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
    }
    dfs(1,adj,visited);
    if(visited[A])return 1;
    return 0;
}
