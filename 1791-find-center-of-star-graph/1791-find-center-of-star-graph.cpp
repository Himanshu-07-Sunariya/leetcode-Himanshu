class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector <int> indegree(n+1,0);

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

            indegree[v]++;
            indegree[u]++;
        }

        for(int i=1; i<=n; i++){
            if(indegree[i]==(n-1)){
                return i;
            }
        }

        return -1;
    }
};