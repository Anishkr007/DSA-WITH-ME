class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        int n=matrix.size();
        int m=matrix[0].size();

        int ans=1;

        if(dp[i][j]!=-1) return dp[i][j];

        int delrow[]={0,0,1,-1};
        int delcol[]={-1,1,0,0};

        for(int k=0;k<4;k++){
            int nr=i+delrow[k];
            int nc=j+delcol[k];

            if(nr>=0 && nc>=0 && nr<n && nc<m && matrix[nr][nc]>matrix[i][j]){
                ans=max(ans,1+solve(nr,nc,matrix,dp));
            }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        int ans=0;

        vector<vector<int>>dp(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,solve(i,j,matrix,dp));
            }
        }

        return ans;
    }
};