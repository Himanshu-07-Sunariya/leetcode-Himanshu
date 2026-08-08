class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // bfs traversal
        vector<vector<int>> adj(n);

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue <int> q;
        vector<int> vis(n,0);
        q.push(source);
        vis[source]=1;

        while(!q.empty()){
            // curr node
            auto curr=q.front();
            q.pop();

            // main case
            if(curr==destination) return true;

            // nbrs
            for(auto it:adj[curr]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }

        return false;
    }
};