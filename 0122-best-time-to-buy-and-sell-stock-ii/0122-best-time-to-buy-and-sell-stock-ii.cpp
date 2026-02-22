class Solution {
public:
//canbuy=1->can buy;
//canbut=0->cannt buy;

    int f(int index,int canbuy,vector<int>& prices,vector<vector<int>>&dp){
        int n=prices.size();

        if(index==n) return 0;
        if(dp[index][canbuy]!=-1) return dp[index][canbuy];

        if(canbuy){
            return dp[index][canbuy]=max((-prices[index]+f(index+1,0,prices,dp)),f(index+1,1,prices,dp));
        }else{
            return dp[index][canbuy]=max((prices[index]+f(index+1,1,prices,dp)),f(index+1,0,prices,dp));
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);

    }
};