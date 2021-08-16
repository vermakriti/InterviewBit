int iscycle(int node,vector<int> adj[],vector<int>&visited,vector<int>&recur){

    if(recur[node])
        return 1;
    if(visited[node])
        return 0;
    visited[node]=1;
    recur[node]=1;
    for(auto child:adj[node]){
        if(iscycle(child,adj,visited,recur))
            return 1;
    }
    recur[node]=0;
    return 0;
}
int Solution::solve(int A, vector<int> &B, vector<int> &C) {

    vector<int> adj[A+2],visited(A+2,0),recur(A+2,0);
    for(int i=0;i<B.size();i++){
        adj[B[i]].push_back(C[i]);
    }
    for(int i=1;i<=A;i++){
        if(!visited[i]){
            if(iscycle(i,adj,visited,recur))
                return 0;
        }
    }
    return 1;

}
