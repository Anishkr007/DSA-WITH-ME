class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int total = 0;

        for(auto x : nums){
            total += x;
        }

        if(abs(target) > total){
            return 0;
        }

        if((target + total) % 2 != 0){
            return 0;
        }

        int sum = (target + total) / 2;

        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){

            for(int j = 0; j <= sum; j++){

                int notTake = dp[i-1][j];

                int take = 0;

                if(nums[i-1] <= j){
                    take = dp[i-1][j-nums[i-1]];
                }

                dp[i][j] = take + notTake;
            }
        }

        return dp[n][sum];
    }
};