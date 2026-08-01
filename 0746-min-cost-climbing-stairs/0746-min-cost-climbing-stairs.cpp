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
        
       int prev2=cost[0];
        int prev1=cost[1];
        int ans=0;

        for(int i=2;i<n;i++){
            ans=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=ans;
        }

        return min(prev1,prev2);
    }
};