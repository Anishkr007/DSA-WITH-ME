class Solution {
public:
    int f(int i,int amt,vector<int>& coins,vector<vector<int>>& dp){
        if(i==0){
            if(amt%coins[0]==0){
                return amt/coins[0];
            }else{
                return 1e9;
            }
        }
        if(dp[i][amt]!=-1) return dp[i][amt];

        //not take
        int nTake=f(i-1,amt,coins,dp);
        //take=0
        int take=1e9;
        if(coins[i]<=amt){
            take=1+f(i,amt-coins[i],coins,dp);
        }

        return dp[i][amt]= min(nTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,coins,dp);

        return (ans>=1e9)?-1:ans;
    }
};