int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+2];
    vector<int> color(A+2,-1);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    queue<int> q;
    for(int i=1;i<=A;i++){
        if(color[i]==-1){
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(auto child:adj[node]){
                    if(color[child]==-1){
                        color[child]=1-color[node];
                        q.push(child);
                    }
                    else if(color[child]==color[node])
                        return 0;
                }
            }
        }
    }
    return 1;
}
