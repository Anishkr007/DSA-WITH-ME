class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(i>=n || j>= m) return 0;
        if(grid[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=solve(i+1,j,n,m,dp,grid)+solve(i,j+1,n,m,dp,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

       return  solve(0,0,n,m,dp,obstacleGrid);
    }
};