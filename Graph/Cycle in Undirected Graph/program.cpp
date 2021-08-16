int Solution::solve(int A, vector<vector<int> > &B) {

    vector<int> adj[A+2],visited(A+2,0);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    queue<pair<int,int>> q;
    for(int i=1;i<=A;i++){
        if(!visited[i]){
            q.push({i,-1});
            visited[i]=1;
            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(auto child:adj[node]){
                    if(!visited[child]){
                        visited[child]=1;
                        q.push({child,node});
                    }
                    else if(parent!=child){
                        return 1;
                    }
                }
            }

        }

    }
    return 0;
}
