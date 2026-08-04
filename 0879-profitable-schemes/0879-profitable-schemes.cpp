class Solution {
public:

    int MOD=1e9+7;

    int solve(int i,int people,int profitEarned,
              int n,int minProfit,
              vector<int>& group,
              vector<int>& profit,
              vector<vector<vector<int>>>& dp){

        if(i==group.size()){

            if(profitEarned>=minProfit)
                return 1;

            return 0;
        }

        if(dp[i][people][profitEarned]!=-1)
            return dp[i][people][profitEarned];

        int notTake=
        solve(i+1,
              people,
              profitEarned,
              n,
              minProfit,
              group,
              profit,
              dp);

        int take=0;

        if(people+group[i]<=n){

            take=
            solve(i+1,
                  people+group[i],
                  min(minProfit,
                      profitEarned+profit[i]),
                  n,
                  minProfit,
                  group,
                  profit,
                  dp);
        }

        return dp[i][people][profitEarned]
        =(take+notTake)%MOD;
    }

    int profitableSchemes(int n,
                          int minProfit,
                          vector<int>& group,
                          vector<int>& profit){

        int m=group.size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n+1,
            vector<int>(minProfit+1,-1)));

        return solve(0,0,0,
                     n,minProfit,
                     group,
                     profit,
                     dp);
    }
};