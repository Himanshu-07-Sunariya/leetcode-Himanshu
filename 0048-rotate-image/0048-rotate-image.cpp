class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> transporse(n,vector<int>(n));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                transporse[j][i]=matrix[i][j];
            }
        }

        for(int i=0; i<n; i++){
            reverse(transporse[i].begin(),transporse[i].end());
        }

        matrix=transporse;
    }
};