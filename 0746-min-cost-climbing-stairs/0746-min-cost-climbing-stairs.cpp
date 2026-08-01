class Solution {
public:
    int solve(int i,vector<int>& cost,vector<int>&dp){
        if(i==0) return cost[0];
        if(i==1) return cost[1];
        if(dp[i]!=-1) return dp[i];

        return dp[i]=cost[i]+min(solve(i-1,cost,dp),solve(i-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n);
        dp[0]=cost[0];
        dp[1]=cost[1];

        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }

        return min(dp[n-1],dp[n-2]);
    }
};