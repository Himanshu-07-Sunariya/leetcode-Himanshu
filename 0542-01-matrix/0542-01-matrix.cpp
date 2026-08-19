class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> visited(m, vector <int> (n,0));

        queue <pair<int,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0 && !visited[i][j]){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            // curr node
            auto curr=q.front();
            q.pop();

            int cr=curr.first;
            int cc=curr.second;

            // self work +nbr work
            // neighbours
            int row[4]={0,1,0,-1};
            int col[4]={-1,0,1,0};

            for(int i=0; i<4; i++){
                int nr=cr+row[i];
                int nc=cc+col[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc]){
                    if(mat[nr][nc]==1){
                        mat[nr][nc]=mat[cr][cc]+1;
                    }

                    q.push({nr,nc});
                    visited[nr][nc]=1;
                }
            }
            
        }

        return mat;
    }
};