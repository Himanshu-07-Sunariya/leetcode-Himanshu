class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // rotten oranges se multisource bfs hoga
        queue <vector<int>> q;

        int ones=0;

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> visited(m, vector <int> (n,0));
        
        // multisource bfs
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({0,i,j});
                    // visited[i][j]=1;
                }
                else if(grid[i][j]==1){
                    ones++;
                }
            }
        }

        if(ones==0) return 0;

        int time=0;
        int count=0;

        while(!q.empty()){
            // curr node start from t=0 waali saari node aaegi for multisource bfs
            auto curr=q.front();
            q.pop();

            // self work
            int t=curr[0];
            int cr=curr[1];
            int cc=curr[2];

            time=max(t,time);

            // neighbours ko rotten kro
            // 4 directional neighbours ko sadao
            int row[4]={-1,0,1,0};
            int col[4]={0,-1,0,1};

            for(int i=0; i<4; i++){
                int nr=cr+row[i];
                int nc=cc+col[i];

                // boundary check
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !visited[nr][nc]){
                    visited[nr][nc]=1;
                    q.push({t+1,nr,nc});
                    count++;
                }
            }
        }

        if(count!=ones){
            return -1;
        }

        return time;
    }
};