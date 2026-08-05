class Solution {
public:
    void dfs(int k,vector <int>& buggy,vector<vector<int>>& adj){
        // mark buggy
        buggy[k]=1;

        //nbrs traverse nbrs mark
        for(auto it:adj[k]){
            if(!buggy[it]){
                dfs(it,buggy,adj);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> directedAdj(n);
        vector<vector<int>> undirectedAdj(n);

        for(auto it:invocations){
            directedAdj[it[0]].push_back(it[1]);
            // directedAdj[it.second].push_back(it.first);
            undirectedAdj[it[0]].push_back(it[1]);
            undirectedAdj[it[1]].push_back(it[0]);
        }

        vector <int> buggy(n,0);

        // mark buggy
        dfs(k,buggy,directedAdj);

        // multisource bfs
        queue <int> q;
        vector <int> vis(n,0);
        for(int i=0; i<buggy.size(); i++){
            if(buggy[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }

        while(!q.empty()){
            //curr node
            auto curr=q.front();
            q.pop();

            if(buggy[curr]==1){
                buggy[curr]=0;
            }

            for(auto it:undirectedAdj[curr]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }

        vector <int> ans;

        for(int i=0; i<buggy.size(); i++){
            if(buggy[i]==0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};