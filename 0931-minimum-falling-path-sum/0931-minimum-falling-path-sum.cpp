class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();

        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int down=dp[i+1][j];
                int left=1e9;
                if(j>0){
                     left=dp[i+1][j-1];
                }
                int right=1e9;
                if(j<n-1){
                     right=dp[i+1][j+1];
                }

                dp[i][j]=min({down,left,right})+matrix[i][j];
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};