class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int up=1e9;
                int dia=1e9;

                up=dp[i+1][j]+triangle[i][j];
                dia=dp[i+1][j+1]+triangle[i][j];

                dp[i][j]=min(up,dia);
            }
        }
        return dp[0][0];
    }
};